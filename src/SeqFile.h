/*
 * ============================================================================
 *
 * SeqFile.h
 * Class to hold/import/export a Nintendo EAD (Audioseq) format sequence file
 * 
 * From seq64 - Sequenced music editor for first-party N64 games
 * Copyright (C) 2014-2019 Sauraen
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ============================================================================
*/

#ifndef SEQFILE_H_INCLUDED
#define SEQFILE_H_INCLUDED

#include "JuceHeader.h"

#define max_layers 4

inline bool isInt(String str, bool allowNegative = true)
{
    str = str.trim();
    if (str.isEmpty())
        return false;
    CharPointer_UTF32 s = str.toUTF32();
    for (int i = 0; i < s.length(); ++s)
    {
        if (s[i] == '-')
        {
            if (i != 0 || !allowNegative || s.length() == 1)
                return false;
            continue;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

inline bool isHex(String str, bool allow0x = true)
{
    str = str.trim().toLowerCase();
    if (str.isEmpty())
        return false;
    if (str.startsWith("0x") && allow0x)
        str = str.substring(2);
    CharPointer_UTF32 s = str.toUTF32();
    for (int i = 0; i < s.length(); ++s)
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f'))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

inline bool isDec(String str, bool allowNegative = true)
{
    str = str.trim();
    if (str.isEmpty())
        return false;
    CharPointer_UTF32 s = str.toUTF32();
    bool decimalpoint = false;
    for (int i = 0; i < s.length(); ++s)
    {
        if (s[i] == '-')
        {
            if (i != 0 || !allowNegative || s.length() == 1)
                return false;
            continue;
        }
        else if (s[i] == '.')
        {
            if (decimalpoint || s.length() == 1)
                return false;
            decimalpoint = true;
            continue;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

template <typename INT_TYPE>
inline String hex(INT_TYPE i, int bits)
{
    String ret;
    while (bits > 0)
    {
        uint8_t nybble = i & 0xF;
        if (nybble <= 9)
            ret = String::charToString('0' + nybble) + ret;
        else
            ret = String::charToString('A' + nybble - 0xA) + ret;
        i >>= 4;
        bits -= 4;
    }
    return ret;
}

inline String hex(uint8_t i) { return hex(i, 8); }
inline String hex(uint16_t i) { return hex(i, 16); }
inline String hex(uint32_t i) { return hex(i, 32); }
inline String hexauto(int i) { return hex(i, i >= 0x10000 ? 32 : i >= 0x100 ? 16
                                                                            : 8); }

class ROM;
class BankFile;

class SeqTSection{
    public:
	SeqTSection();

    uint32 time;
    uint32 address;
    uint32 address_end;
};

class SeqData{
    public:
	SeqData();

    uint32 address;
    uint32 address_end;
    int8 stype;
    int8 channel;
    int8 layer;
    int8 calldepth;
    int8 finished;
    int16 tsection;
    Array<uint32> cmdoffsets;
};

class CCTracker{
    public:
    CCTracker();
    
    String action;
    int q_time;
    int lasttime;
    int q_amp;
    int lastvalue;
    ValueTree lastcmd;
    bool warnedUnused;
};

enum CCCommands {
    CC_SOUND_BANK = 0,
    CC_MODULATION = 1,
    CC_VOLUME = 7,
    CC_PAN = 10,
    CC_VOLUME_EXPR = 11,
    CC_PRIORITY_GPC1 = 16,
    CC_PRIORITY_GPC2 = 17,
    CC_NONE_24 = 24,
    CC_PRIORITY_ELSE = 25,
    CC_VIBRATO_RATE = 76,
    CC_VIBRATO_EXTENT = 77,
    CC_RELEASE_RATE = 78,
    CC_PRIORITY_SC10 = 79,
    CC_PRIORITY_US = 85,
    CC_8BIT_WAVE_INDEX = 87,
    CC_CHN_LYR_PAN_MIX = 89,
    CC_TRANSPOSE = 90,
    CC_REVERB = 91,
    CC_FLSTUDIO_MST_VOL = 114,
    CC_FLSTUDIO_MARKER = 115,
    CC_PITCH_BEND = 128,
    CC_INSTRUMENT = 129,

    CC_TOTAL = 130
};


class SeqFile{
    public:
    SeqFile(ValueTree romdesc_);
    ~SeqFile();

    String seqname;
    StringArray tsecnames;
    
    uint32 getLength();
    uint8 readByte(uint32 address);
    void writeByte(uint32 address, uint8 d);
    
    bool load(ROM& rom, int seqnumber);
    void saveToROM(ROM& rom, uint32 start_addr);
    bool loadRaw(File file);
    bool saveRaw(File file);
    
    void trim();
    void parse();
    int getNumSections();
    SeqData* getSection(int s);
    String getSectionDescription(int s);
    String getCommandDescription(int s, int c);
    
    ValueTree getDescription(uint8 firstbyte, int stype); //Stype: 0 seq hdr, 1 chn hdr, 2 track data
    ValueTree getCommand(uint32 address, int stype);
    int getAdjustedValue(const ValueTree& param);
    int getPtrAddress(ValueTree command, uint32 currentAddr);
    SeqData* getOrMakeSectionAt(uint32 a);
    bool isSectionAt(uint32 a, int stype);
    bool isCommandValidIn(ValueTree command, int stype);
    int getCommandRange(ValueTree command, String meaning);
    int getLargestCommandRange(int stype, String action, String meaning);
    
    void insertSpaceAt(uint32 address, int size, int enlargeSection); //If inserting at a section boundary, enlargeSection controls which section gets the new data
    void removeData(uint32 address, int size, int shrinkSection);
    void editCmdPointer(uint32 cmdaddr, int stype, uint32 daddr, int dsize, int addrOfChangeSection);
    int editCmdParam(int section, uint32 address, int stype, String meaning, int newvalue); //0 okay, -1 failed, 1 structure changed
    bool swapCommands(int sectionidx, int firstcmdidx);
    
    ValueTree wantAction(String action, int stype);
    void wantProperty(ValueTree want, String meaning, int value);
    ValueTree createCommand(ValueTree want, bool warnIfImpossible = true);
    void advanceToTimestamp(ValueTree section, int stype, int &cmd, int &t, int newt);
    ValueTree createMarker();
    int getNewCommandLength(ValueTree command); //For a command that was just created, not one read from an existing sequence
    void writeCommand(uint32 address, ValueTree command); //Overwrite whatever is at address, don't resize
    void insertCommand(int section, int cmdidx, ValueTree command);
    void deleteCommand(int section, int cmdidx);
    
    MidiMessageSequence* ensureSimulMsgsInOrder(MidiMessageSequence &in);
    MidiFile* toMIDIFile(ROM& rom);
    void deleteSection(int sectodelete);
    void fromMidiFile(MidiFile& mfile);

    void dbgmsg(String s, bool newline = true);

    bool SeqFile::isValidCC(int cc);
    void SeqFile::getExtendedCC(MidiMessage msg, int &cc, int &value);
    void SeqFile::prefSetBool(Identifier opt, String value, String prefline);
    void SeqFile::prefSetInt(Identifier opt, int max, String value, String prefline);
    void SeqFile::prefSetHex(Identifier opt, int max, String value, String prefline);
    int SeqFile::importMIDIV2(File midifile);

    void SeqFile::optimizeV2();
    bool SeqFile::isCloseEnoughV2(ValueTree command1, ValueTree command2, bool allowCCMerge);

    bool isCloseEnough(ValueTree command1, ValueTree command2, bool allowCCMerge);
    int getTotalSectionTime(ValueTree section);
    
    void optimize();
    void reduceTrackNotes();
    void render();
    
    String name;
    
    int importresult; //0 okay, 1 warnings, 2 errors
    
    private:
    Array<uint8> data;
    ValueTree structure;
    
    ValueTree romdesc;
    ValueTree cmdlist;
    ValueTree midiopts;
    
    int bank_num;
    
    OwnedArray<SeqData> sections;
    
    bool debug;
    
    static Identifier idCC;
    static Identifier idSrcCmdRef;
    static Identifier idName;
    static Identifier idLength;
    static Identifier idAction;
    static Identifier idCmd;
    static Identifier idCmdEnd;
    static Identifier idMeaning;
    static Identifier idValue;
    static Identifier idAdd;
    static Identifier idMultiply;
    static Identifier idDataSrc;
    static Identifier idDataLen;
    static Identifier idDataAddr;
    static Identifier idDataActualLen;
    static Identifier idValidInSeq;
    static Identifier idValidInChn;
    static Identifier idValidInTrk;
    
    static Identifier idSType;
    static Identifier idChannel;
    static Identifier idLayer;
    static Identifier idTSection;
    static Identifier idSection;
    static Identifier idAddress;
    static Identifier idAddressEnd;
    static Identifier idHash;
    static Identifier idTargetSection;
    static Identifier idTargetHash;
    static Identifier idWillDrop;
    
};



#endif  // SEQFILE_H_INCLUDED
