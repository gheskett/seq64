/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
/*
 * ============================================================================
 *
 * MidiPane.cpp
 * GUI component for the MIDI import/export screen
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

#include "MainComponent.h"
#include "SeqFile.h"
//[/Headers]

#include "MidiPane.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidiPane::MidiPane (SEQ64& seq64_)
    : seq64(seq64_)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponent8.reset (new GroupComponent ("new group",
                                               TRANS("Import Settings")));
    addAndMakeVisible (groupComponent8.get());

    groupComponent8->setBounds (360, 8, 352, 432);

    groupComponent3.reset (new GroupComponent ("new group",
                                               TRANS("Optimization")));
    addAndMakeVisible (groupComponent3.get());

    groupComponent3->setBounds (368, 240, 336, 192);

    groupComponent7.reset (new GroupComponent ("new group",
                                               TRANS("Export Settings")));
    addAndMakeVisible (groupComponent7.get());

    groupComponent7->setBounds (0, 160, 352, 192);

    groupComponent.reset (new GroupComponent ("new group",
                                              TRANS("Global")));
    addAndMakeVisible (groupComponent.get());

    groupComponent->setBounds (0, 56, 352, 96);

    btnMIDIExport.reset (new TextButton ("new button"));
    addAndMakeVisible (btnMIDIExport.get());
    btnMIDIExport->setButtonText (TRANS("Export MIDI"));
    btnMIDIExport->setConnectedEdges (Button::ConnectedOnRight);
    btnMIDIExport->addListener (this);

    btnMIDIExport->setBounds (0, 24, 176, 24);

    btnMIDIImport.reset (new TextButton ("new button"));
    addAndMakeVisible (btnMIDIImport.get());
    btnMIDIImport->setButtonText (TRANS("Import MIDI"));
    btnMIDIImport->setConnectedEdges (Button::ConnectedOnLeft);
    btnMIDIImport->addListener (this);

    btnMIDIImport->setBounds (176, 24, 176, 24);

    label20.reset (new Label ("new label",
                              TRANS("Bend range:")));
    addAndMakeVisible (label20.get());
    label20->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label20->setJustificationType (Justification::centredLeft);
    label20->setEditable (false, false, false);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label20->setBounds (8, 175, 88, 24);

    txtMIDIBend.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtMIDIBend.get());
    txtMIDIBend->setMultiLine (false);
    txtMIDIBend->setReturnKeyStartsNewLine (false);
    txtMIDIBend->setReadOnly (false);
    txtMIDIBend->setScrollbarsShown (true);
    txtMIDIBend->setCaretVisible (true);
    txtMIDIBend->setPopupMenuEnabled (true);
    txtMIDIBend->setText (TRANS("6"));

    txtMIDIBend->setBounds (96, 175, 32, 24);

    label21.reset (new Label ("new label",
                              TRANS("PPQN multiplier:")));
    addAndMakeVisible (label21.get());
    label21->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label21->setJustificationType (Justification::centredLeft);
    label21->setEditable (false, false, false);
    label21->setColour (TextEditor::textColourId, Colours::black);
    label21->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label21->setBounds (136, 175, 120, 24);

    txtMIDIPPQN.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtMIDIPPQN.get());
    txtMIDIPPQN->setMultiLine (false);
    txtMIDIPPQN->setReturnKeyStartsNewLine (false);
    txtMIDIPPQN->setReadOnly (false);
    txtMIDIPPQN->setScrollbarsShown (true);
    txtMIDIPPQN->setCaretVisible (true);
    txtMIDIPPQN->setPopupMenuEnabled (true);
    txtMIDIPPQN->setText (TRANS("2"));

    txtMIDIPPQN->setBounds (248, 175, 32, 24);

    label22.reset (new Label ("new label",
                              TRANS("x48")));
    addAndMakeVisible (label22.get());
    label22->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label22->setJustificationType (Justification::centredLeft);
    label22->setEditable (false, false, false);
    label22->setColour (TextEditor::textColourId, Colours::black);
    label22->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label22->setBounds (280, 175, 32, 24);

    label23.reset (new Label ("new label",
                              TRANS("Chn volume to:")));
    addAndMakeVisible (label23.get());
    label23->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label23->setJustificationType (Justification::centredLeft);
    label23->setEditable (false, false, false);
    label23->setColour (TextEditor::textColourId, Colours::black);
    label23->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label23->setBounds (8, 71, 120, 24);

    cbxMIDIChnVol.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (cbxMIDIChnVol.get());
    cbxMIDIChnVol->setEditableText (false);
    cbxMIDIChnVol->setJustificationType (Justification::centredLeft);
    cbxMIDIChnVol->setTextWhenNothingSelected (TRANS("ERROR"));
    cbxMIDIChnVol->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    cbxMIDIChnVol->addItem (TRANS("CC7 (Volume)"), 1);
    cbxMIDIChnVol->addItem (TRANS("CC11 (Expr)"), 2);
    cbxMIDIChnVol->addListener (this);

    cbxMIDIChnVol->setBounds (128, 71, 216, 24);

    label24.reset (new Label ("new label",
                              TRANS("Master volume to:")));
    addAndMakeVisible (label24.get());
    label24->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label24->setJustificationType (Justification::centredLeft);
    label24->setEditable (false, false, false);
    label24->setColour (TextEditor::textColourId, Colours::black);
    label24->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label24->setBounds (8, 95, 120, 24);

    cbxMIDIMtrVol.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (cbxMIDIMtrVol.get());
    cbxMIDIMtrVol->setEditableText (false);
    cbxMIDIMtrVol->setJustificationType (Justification::centredLeft);
    cbxMIDIMtrVol->setTextWhenNothingSelected (TRANS("ERROR"));
    cbxMIDIMtrVol->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    cbxMIDIMtrVol->addItem (TRANS("CC7 (Volume)"), 1);
    cbxMIDIMtrVol->addItem (TRANS("CC11 (Expr)"), 2);
    cbxMIDIMtrVol->addItem (TRANS("CC16 (GPC1)"), 3);
    cbxMIDIMtrVol->addItem (TRANS("CC24 (None)"), 4);
    cbxMIDIMtrVol->addItem (TRANS("SysEx MstrVol"), 5);
    cbxMIDIMtrVol->addListener (this);

    cbxMIDIMtrVol->setBounds (128, 95, 216, 24);

    label26.reset (new Label ("new label",
                              TRANS("Chn priority to:")));
    addAndMakeVisible (label26.get());
    label26->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label26->setJustificationType (Justification::centredLeft);
    label26->setEditable (false, false, false);
    label26->setColour (TextEditor::textColourId, Colours::black);
    label26->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label26->setBounds (8, 119, 120, 24);

    cbxChnPriority.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (cbxChnPriority.get());
    cbxChnPriority->setEditableText (false);
    cbxChnPriority->setJustificationType (Justification::centredLeft);
    cbxChnPriority->setTextWhenNothingSelected (TRANS("ERROR"));
    cbxChnPriority->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    cbxChnPriority->addItem (TRANS("CC17 (GPC2)"), 1);
    cbxChnPriority->addItem (TRANS("CC25 (None)"), 2);
    cbxChnPriority->addItem (TRANS("CC79 (SC10)"), 3);
    cbxChnPriority->addListener (this);

    cbxChnPriority->setBounds (128, 119, 216, 24);

    optSeqFormat.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optSeqFormat.get());
    optSeqFormat->setButtonText (TRANS("Create Seq Format cmd:"));
    optSeqFormat->addListener (this);
    optSeqFormat->setToggleState (true, dontSendNotification);

    optSeqFormat->setBounds (368, 24, 184, 24);

    optSeqType.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optSeqType.get());
    optSeqType->setButtonText (TRANS("Create Seq Type cmd:"));
    optSeqType->addListener (this);
    optSeqType->setToggleState (true, dontSendNotification);

    optSeqType->setBounds (368, 48, 184, 24);

    optChanBits.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optChanBits.get());
    optChanBits->setButtonText (TRANS("Create Channel Enable/Disable Bitfield Cmds"));
    optChanBits->addListener (this);
    optChanBits->setToggleState (true, dontSendNotification);

    optChanBits->setBounds (368, 72, 336, 24);

    optLoopAll.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optLoopAll.get());
    optLoopAll->setButtonText (TRANS("Create command to loop whole sequence"));
    optLoopAll->addListener (this);
    optLoopAll->setToggleState (true, dontSendNotification);

    optLoopAll->setBounds (368, 120, 336, 24);

    optHeader.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optHeader.get());
    optHeader->setButtonText (TRANS("Create jump-to-sections header (if sections defined)"));
    optHeader->addListener (this);

    optHeader->setBounds (368, 144, 336, 24);

    optChanReset.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optChanReset.get());
    optChanReset->setButtonText (TRANS("Initially reset channels"));
    optChanReset->addListener (this);
    optChanReset->setToggleState (true, dontSendNotification);

    optChanReset->setBounds (368, 168, 336, 24);

    grpPtr.reset (new GroupComponent ("new group",
                                      TRANS("Pointer Type")));
    addAndMakeVisible (grpPtr.get());

    grpPtr->setBounds (368, 192, 336, 48);

    optPtrAbsolute.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optPtrAbsolute.get());
    optPtrAbsolute->setButtonText (TRANS("Absolute"));
    optPtrAbsolute->setRadioGroupId (1);
    optPtrAbsolute->addListener (this);

    optPtrAbsolute->setBounds (464, 208, 88, 24);

    optPtrShortest.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optPtrShortest.get());
    optPtrShortest->setButtonText (TRANS("Shortest"));
    optPtrShortest->setRadioGroupId (1);
    optPtrShortest->addListener (this);

    optPtrShortest->setBounds (376, 208, 80, 24);

    optPtrRelative.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optPtrRelative.get());
    optPtrRelative->setButtonText (TRANS("Force Relative Only"));
    optPtrRelative->setRadioGroupId (1);
    optPtrRelative->addListener (this);

    optPtrRelative->setBounds (552, 208, 144, 24);

    txtSeqFormat.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtSeqFormat.get());
    txtSeqFormat->setMultiLine (false);
    txtSeqFormat->setReturnKeyStartsNewLine (false);
    txtSeqFormat->setReadOnly (false);
    txtSeqFormat->setScrollbarsShown (true);
    txtSeqFormat->setCaretVisible (true);
    txtSeqFormat->setPopupMenuEnabled (true);
    txtSeqFormat->setText (TRANS("20"));

    txtSeqFormat->setBounds (560, 24, 40, 24);

    txtSeqType.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtSeqType.get());
    txtSeqType->setMultiLine (false);
    txtSeqType->setReturnKeyStartsNewLine (false);
    txtSeqType->setReadOnly (false);
    txtSeqType->setScrollbarsShown (true);
    txtSeqType->setCaretVisible (true);
    txtSeqType->setPopupMenuEnabled (true);
    txtSeqType->setText (TRANS("32"));

    txtSeqType->setBounds (560, 48, 40, 24);

    optCalls.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optCalls.get());
    optCalls->setButtonText (TRANS("Use Calls"));
    optCalls->addListener (this);
    optCalls->setToggleState (true, dontSendNotification);

    optCalls->setBounds (376, 280, 144, 24);

    lblStack.reset (new Label ("new label",
                               TRANS("Stack height:")));
    addAndMakeVisible (lblStack.get());
    lblStack->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    lblStack->setJustificationType (Justification::centredLeft);
    lblStack->setEditable (false, false, false);
    lblStack->setColour (TextEditor::textColourId, Colours::black);
    lblStack->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    lblStack->setBounds (376, 256, 104, 24);

    txtStack.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtStack.get());
    txtStack->setMultiLine (false);
    txtStack->setReturnKeyStartsNewLine (false);
    txtStack->setReadOnly (false);
    txtStack->setScrollbarsShown (true);
    txtStack->setCaretVisible (true);
    txtStack->setPopupMenuEnabled (true);
    txtStack->setText (TRANS("4"));

    txtStack->setBounds (480, 256, 40, 24);

    optLoops.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optLoops.get());
    optLoops->setButtonText (TRANS("Use Loops"));
    optLoops->addListener (this);
    optLoops->setToggleState (true, dontSendNotification);

    optLoops->setBounds (376, 304, 144, 24);

    label2.reset (new Label ("new label",
                             TRANS("Merge Even If Off By:")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (376, 328, 144, 24);

    txtMergeVels.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtMergeVels.get());
    txtMergeVels->setMultiLine (false);
    txtMergeVels->setReturnKeyStartsNewLine (false);
    txtMergeVels->setReadOnly (false);
    txtMergeVels->setScrollbarsShown (true);
    txtMergeVels->setCaretVisible (true);
    txtMergeVels->setPopupMenuEnabled (true);
    txtMergeVels->setText (TRANS("5"));

    txtMergeVels->setBounds (480, 352, 40, 24);

    txtMergeGates.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtMergeGates.get());
    txtMergeGates->setMultiLine (false);
    txtMergeGates->setReturnKeyStartsNewLine (false);
    txtMergeGates->setReadOnly (false);
    txtMergeGates->setScrollbarsShown (true);
    txtMergeGates->setCaretVisible (true);
    txtMergeGates->setPopupMenuEnabled (true);
    txtMergeGates->setText (TRANS("3"));

    txtMergeGates->setBounds (480, 376, 40, 24);

    txtMergeCCs.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtMergeCCs.get());
    txtMergeCCs->setMultiLine (false);
    txtMergeCCs->setReturnKeyStartsNewLine (false);
    txtMergeCCs->setReadOnly (false);
    txtMergeCCs->setScrollbarsShown (true);
    txtMergeCCs->setCaretVisible (true);
    txtMergeCCs->setPopupMenuEnabled (true);
    txtMergeCCs->setText (TRANS("1"));

    txtMergeCCs->setBounds (480, 400, 40, 24);

    label3.reset (new Label ("new label",
                             TRANS("CC Bandwidth Reduction:")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (528, 256, 168, 24);

    label4.reset (new Label ("new label",
                             TRANS("Quantize in: time    ampl")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (528, 280, 168, 24);

    txtQVolT.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQVolT.get());
    txtQVolT->setMultiLine (false);
    txtQVolT->setReturnKeyStartsNewLine (false);
    txtQVolT->setReadOnly (false);
    txtQVolT->setScrollbarsShown (true);
    txtQVolT->setCaretVisible (true);
    txtQVolT->setPopupMenuEnabled (true);
    txtQVolT->setText (TRANS("0"));

    txtQVolT->setBounds (608, 304, 40, 24);

    txtQOtherT.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQOtherT.get());
    txtQOtherT->setMultiLine (false);
    txtQOtherT->setReturnKeyStartsNewLine (false);
    txtQOtherT->setReadOnly (false);
    txtQOtherT->setScrollbarsShown (true);
    txtQOtherT->setCaretVisible (true);
    txtQOtherT->setPopupMenuEnabled (true);
    txtQOtherT->setText (TRANS("0"));

    txtQOtherT->setBounds (608, 376, 40, 24);

    txtQVolA.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQVolA.get());
    txtQVolA->setMultiLine (false);
    txtQVolA->setReturnKeyStartsNewLine (false);
    txtQVolA->setReadOnly (false);
    txtQVolA->setScrollbarsShown (true);
    txtQVolA->setCaretVisible (true);
    txtQVolA->setPopupMenuEnabled (true);
    txtQVolA->setText (TRANS("2"));

    txtQVolA->setBounds (656, 304, 40, 24);

    txtQOtherA.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQOtherA.get());
    txtQOtherA->setMultiLine (false);
    txtQOtherA->setReturnKeyStartsNewLine (false);
    txtQOtherA->setReadOnly (false);
    txtQOtherA->setScrollbarsShown (true);
    txtQOtherA->setCaretVisible (true);
    txtQOtherA->setPopupMenuEnabled (true);
    txtQOtherA->setText (TRANS("1"));

    txtQOtherA->setBounds (656, 376, 40, 24);

    label5.reset (new Label ("new label",
                             TRANS("From/To Audioseq tab:")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (0, 0, 344, 24);

    label6.reset (new Label ("new label",
                             TRANS("- Volume")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (528, 304, 72, 24);

    label7.reset (new Label ("new label",
                             TRANS("- Other")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (528, 376, 72, 24);

    label8.reset (new Label ("new label",
                             TRANS("- Velocities")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (376, 352, 88, 24);

    label9.reset (new Label ("new label",
                             TRANS("- Gate Times")));
    addAndMakeVisible (label9.get());
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label9->setBounds (376, 376, 88, 24);

    label10.reset (new Label ("new label",
                              TRANS("- CCs")));
    addAndMakeVisible (label10.get());
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label10->setBounds (376, 400, 88, 24);

    txtQPitchT.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQPitchT.get());
    txtQPitchT->setMultiLine (false);
    txtQPitchT->setReturnKeyStartsNewLine (false);
    txtQPitchT->setReadOnly (false);
    txtQPitchT->setScrollbarsShown (true);
    txtQPitchT->setCaretVisible (true);
    txtQPitchT->setPopupMenuEnabled (true);
    txtQPitchT->setText (TRANS("0"));

    txtQPitchT->setBounds (608, 328, 40, 24);

    txtQPitchA.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQPitchA.get());
    txtQPitchA->setMultiLine (false);
    txtQPitchA->setReturnKeyStartsNewLine (false);
    txtQPitchA->setReadOnly (false);
    txtQPitchA->setScrollbarsShown (true);
    txtQPitchA->setCaretVisible (true);
    txtQPitchA->setPopupMenuEnabled (true);
    txtQPitchA->setText (TRANS("1"));

    txtQPitchA->setBounds (656, 328, 40, 24);

    label11.reset (new Label ("new label",
                              TRANS("- Pitch")));
    addAndMakeVisible (label11.get());
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label11->setBounds (528, 328, 72, 24);

    txtQPanT.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQPanT.get());
    txtQPanT->setMultiLine (false);
    txtQPanT->setReturnKeyStartsNewLine (false);
    txtQPanT->setReadOnly (false);
    txtQPanT->setScrollbarsShown (true);
    txtQPanT->setCaretVisible (true);
    txtQPanT->setPopupMenuEnabled (true);
    txtQPanT->setText (TRANS("0"));

    txtQPanT->setBounds (608, 352, 40, 24);

    txtQPanA.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtQPanA.get());
    txtQPanA->setMultiLine (false);
    txtQPanA->setReturnKeyStartsNewLine (false);
    txtQPanA->setReadOnly (false);
    txtQPanA->setScrollbarsShown (true);
    txtQPanA->setCaretVisible (true);
    txtQPanA->setPopupMenuEnabled (true);
    txtQPanA->setText (TRANS("2"));

    txtQPanA->setBounds (656, 352, 40, 24);

    label12.reset (new Label ("new label",
                              TRANS("- Pan/FX")));
    addAndMakeVisible (label12.get());
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label12->setBounds (528, 352, 72, 24);

    optMstrVol.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optMstrVol.get());
    optMstrVol->setButtonText (TRANS("Add Master Volume cmd if not in MIDI: "));
    optMstrVol->addListener (this);
    optMstrVol->setToggleState (true, dontSendNotification);

    optMstrVol->setBounds (368, 96, 272, 24);

    txtMstrVol.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (txtMstrVol.get());
    txtMstrVol->setMultiLine (false);
    txtMstrVol->setReturnKeyStartsNewLine (false);
    txtMstrVol->setReadOnly (false);
    txtMstrVol->setScrollbarsShown (true);
    txtMstrVol->setCaretVisible (true);
    txtMstrVol->setPopupMenuEnabled (true);
    txtMstrVol->setText (TRANS("58"));

    txtMstrVol->setBounds (640, 96, 40, 24);

    groupComponent2.reset (new GroupComponent ("new group",
                                               TRANS("Export Format")));
    addAndMakeVisible (groupComponent2.get());

    groupComponent2->setBounds (8, 200, 336, 144);

    optExportOrig.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optExportOrig.get());
    optExportOrig->setButtonText (TRANS("Original (for edit + re-import)"));
    optExportOrig->setRadioGroupId (2);
    optExportOrig->addListener (this);

    optExportOrig->setBounds (16, 216, 320, 24);

    optExportGM.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optExportGM.get());
    optExportGM->setButtonText (TRANS("General MIDI (for playback)"));
    optExportGM->setRadioGroupId (2);
    optExportGM->addListener (this);
    optExportGM->setToggleState (true, dontSendNotification);

    optExportGM->setBounds (16, 240, 320, 24);

    label.reset (new Label ("new label",
                            TRANS("Instrument to drums:")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (32, 264, 304, 24);

    optInstDrumCh10.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optInstDrumCh10.get());
    optInstDrumCh10->setButtonText (TRANS("Force Ch. 10 (more compatible, less accurate)"));
    optInstDrumCh10->setRadioGroupId (3);
    optInstDrumCh10->addListener (this);
    optInstDrumCh10->setToggleState (true, dontSendNotification);

    optInstDrumCh10->setBounds (40, 288, 296, 24);

    optInstDrumMulti.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (optInstDrumMulti.get());
    optInstDrumMulti->setButtonText (TRANS("Many Drum Chns Hack (less compatible)"));
    optInstDrumMulti->setRadioGroupId (3);
    optInstDrumMulti->addListener (this);

    optInstDrumMulti->setBounds (40, 312, 296, 24);

    internalPath1.startNewSubPath (32.0f, 264.0f);
    internalPath1.lineTo (32.0f, 336.0f);
    internalPath1.closeSubPath();


    //[UserPreSize]

    txtMIDIBend->addListener(this);
    txtMIDIPPQN->addListener(this);
    txtSeqFormat->addListener(this);
    txtSeqType->addListener(this);
    txtMstrVol->addListener(this);
    txtStack->addListener(this);
    txtMergeVels->addListener(this);
    txtMergeGates->addListener(this);
    txtMergeCCs->addListener(this);
    txtQVolT->addListener(this);
    txtQVolA->addListener(this);
    txtQPitchT->addListener(this);
    txtQPitchA->addListener(this);
    txtQPanT->addListener(this);
    txtQPanA->addListener(this);
    txtQOtherT->addListener(this);
    txtQOtherA->addListener(this);

    cbxMIDIChnVol->setSelectedItemIndex(0, dontSendNotification);
    cbxMIDIMtrVol->setSelectedItemIndex(3, dontSendNotification);
    cbxChnPriority->setSelectedItemIndex(1, dontSendNotification);

    optHeader->setEnabled(false);
    lblStack->setEnabled(false);
    txtStack->setEnabled(false);
    grpPtr->setEnabled(false);
    optPtrShortest->setEnabled(false);
    optPtrAbsolute->setEnabled(false);
    optPtrRelative->setEnabled(false);

    //[/UserPreSize]

    setSize (1078, 713);


    //[Constructor] You can add your own custom stuff here..
    midioptsnode = seq64.romdesc.getOrCreateChildWithName("midiopts", nullptr);

    //[/Constructor]
}

MidiPane::~MidiPane()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent8 = nullptr;
    groupComponent3 = nullptr;
    groupComponent7 = nullptr;
    groupComponent = nullptr;
    btnMIDIExport = nullptr;
    btnMIDIImport = nullptr;
    label20 = nullptr;
    txtMIDIBend = nullptr;
    label21 = nullptr;
    txtMIDIPPQN = nullptr;
    label22 = nullptr;
    label23 = nullptr;
    cbxMIDIChnVol = nullptr;
    label24 = nullptr;
    cbxMIDIMtrVol = nullptr;
    label26 = nullptr;
    cbxChnPriority = nullptr;
    optSeqFormat = nullptr;
    optSeqType = nullptr;
    optChanBits = nullptr;
    optLoopAll = nullptr;
    optHeader = nullptr;
    optChanReset = nullptr;
    grpPtr = nullptr;
    optPtrAbsolute = nullptr;
    optPtrShortest = nullptr;
    optPtrRelative = nullptr;
    txtSeqFormat = nullptr;
    txtSeqType = nullptr;
    optCalls = nullptr;
    lblStack = nullptr;
    txtStack = nullptr;
    optLoops = nullptr;
    label2 = nullptr;
    txtMergeVels = nullptr;
    txtMergeGates = nullptr;
    txtMergeCCs = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    txtQVolT = nullptr;
    txtQOtherT = nullptr;
    txtQVolA = nullptr;
    txtQOtherA = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    label7 = nullptr;
    label8 = nullptr;
    label9 = nullptr;
    label10 = nullptr;
    txtQPitchT = nullptr;
    txtQPitchA = nullptr;
    label11 = nullptr;
    txtQPanT = nullptr;
    txtQPanA = nullptr;
    label12 = nullptr;
    optMstrVol = nullptr;
    txtMstrVol = nullptr;
    groupComponent2 = nullptr;
    optExportOrig = nullptr;
    optExportGM = nullptr;
    label = nullptr;
    optInstDrumCh10 = nullptr;
    optInstDrumMulti = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiPane::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        float x = 0, y = 0;
        Colour strokeColour = Colour (0xff474747);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.strokePath (internalPath1, PathStrokeType (2.000f), AffineTransform::translation(x, y));
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiPane::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidiPane::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == btnMIDIExport.get())
    {
        //[UserButtonCode_btnMIDIExport] -- add your button handler code here..
        if(&*seq64.seq == nullptr) return;
		File dest = SEQ64::readFolderProperty("midifolder");
		dest = dest.getChildFile(File::createLegalFileName(seq64.seq->name) + ".mid");
        FileChooser box("Save As", dest, "*.mid", SEQ64::useNativeFileChooser());
        if(!box.browseForFileToSave(true)) return;
		dest = box.getResult();
        if(!dest.hasWriteAccess()){
            SEQ64::say("Cannot write to " + dest.getFullPathName() + "!");
            return;
        }
        if(dest.getFileExtension() == ""){
            dest = dest.withFileExtension(".mid");
        }
        if(dest.exists()){
            dest.deleteFile();
        }
		SEQ64::writeProperty("midifolder", dest.getParentDirectory().getFullPathName());
        FileOutputStream fos(dest);
        //Do it!
        std::unique_ptr<MidiFile> midi;
        midi.reset(seq64.seq->toMIDIFile(seq64.rom));
        midi->writeTo(fos);
        SEQ64::say("Written!");
        //[/UserButtonCode_btnMIDIExport]
    }
    else if (buttonThatWasClicked == btnMIDIImport.get())
    {
        //[UserButtonCode_btnMIDIImport] -- add your button handler code here..
        if(seq64.seq != nullptr){
            if(!NativeMessageBox::showOkCancelBox(AlertWindow::WarningIcon,
                    "Overwrite?", "A sequence is already loaded, overwrite it?", nullptr, nullptr)) return;
        }
        File dest = SEQ64::readFolderProperty("midiimportfolder");
        FileChooser box("Select a MIDI to load...", dest, "*.mid;*.midi;*.rmi", SEQ64::useNativeFileChooser());
        if(!box.browseForFileToOpen()) return;
        dest = box.getResult();
        if(!dest.existsAsFile()){
            SEQ64::say("File " + dest.getFullPathName() + " does not exist!");
            return;
        }
        SEQ64::writeProperty("midiimportfolder", dest.getParentDirectory().getFullPathName());



        std::unique_ptr<MidiFile> midi;
        midi.reset(new MidiFile());
        FileInputStream fis(dest);
        midi->readFrom(fis);
        seq64.seq.reset(new SeqFile(seq64.romdesc));
        seq64.seq->name = dest.getFileNameWithoutExtension();
        seq64.seq->fromMidiFile(*midi);

        // SEQ64 TODO:
        // seq64.seq.reset(new SeqFile(seq64.romdesc));
        // seq64.seq->importresult = seq64.seq->importMIDIV2(dest);


        seq64.maincomponent->onSeqLoaded();
        if(seq64.seq->importresult == 0){
            NativeMessageBox::showMessageBox(AlertWindow::InfoIcon, "seq64", 
                "MIDI import succeeded!");
        }else if(seq64.seq->importresult == 1){
            NativeMessageBox::showMessageBox(AlertWindow::WarningIcon, "seq64", 
                "MIDI import completed, but there were warnings, see the terminal"
                " output for details.");
        }else{
            NativeMessageBox::showMessageBox(AlertWindow::WarningIcon, "seq64", 
                "MIDI import failed, see the terminal output for details.");
        }
        //[/UserButtonCode_btnMIDIImport]
    }
    else if (buttonThatWasClicked == optSeqFormat.get())
    {
        //[UserButtonCode_optSeqFormat] -- add your button handler code here..
        midioptsnode.setProperty("writeseqformat", optSeqFormat->getToggleState(), nullptr);
        //[/UserButtonCode_optSeqFormat]
    }
    else if (buttonThatWasClicked == optSeqType.get())
    {
        //[UserButtonCode_optSeqType] -- add your button handler code here..
        midioptsnode.setProperty("writeseqtype", optSeqType->getToggleState(), nullptr);
        //[/UserButtonCode_optSeqType]
    }
    else if (buttonThatWasClicked == optChanBits.get())
    {
        //[UserButtonCode_optChanBits] -- add your button handler code here..
        midioptsnode.setProperty("writechanbits", optChanBits->getToggleState(), nullptr);
        //[/UserButtonCode_optChanBits]
    }
    else if (buttonThatWasClicked == optLoopAll.get())
    {
        //[UserButtonCode_optLoopAll] -- add your button handler code here..
        midioptsnode.setProperty("writeloopall", optLoopAll->getToggleState(), nullptr);
        //[/UserButtonCode_optLoopAll]
    }
    else if (buttonThatWasClicked == optHeader.get())
    {
        //[UserButtonCode_optHeader] -- add your button handler code here..
        midioptsnode.setProperty("writeheader", optHeader->getToggleState(), nullptr);
        //[/UserButtonCode_optHeader]
    }
    else if (buttonThatWasClicked == optChanReset.get())
    {
        //[UserButtonCode_optChanReset] -- add your button handler code here..
        midioptsnode.setProperty("writechanreset", optChanReset->getToggleState(), nullptr);
        //[/UserButtonCode_optChanReset]
    }
    else if (buttonThatWasClicked == optPtrAbsolute.get())
    {
        //[UserButtonCode_optPtrAbsolute] -- add your button handler code here..
        midioptsnode.setProperty("ptrtype", "absolute", nullptr);
        //[/UserButtonCode_optPtrAbsolute]
    }
    else if (buttonThatWasClicked == optPtrShortest.get())
    {
        //[UserButtonCode_optPtrShortest] -- add your button handler code here..
        midioptsnode.setProperty("ptrtype", "shortest", nullptr);
        //[/UserButtonCode_optPtrShortest]
    }
    else if (buttonThatWasClicked == optPtrRelative.get())
    {
        //[UserButtonCode_optPtrRelative] -- add your button handler code here..
        midioptsnode.setProperty("ptrtype", "relative", nullptr);
        //[/UserButtonCode_optPtrRelative]
    }
    else if (buttonThatWasClicked == optCalls.get())
    {
        //[UserButtonCode_optCalls] -- add your button handler code here..
        midioptsnode.setProperty("usecalls", optCalls->getToggleState(), nullptr);
        //[/UserButtonCode_optCalls]
    }
    else if (buttonThatWasClicked == optLoops.get())
    {
        //[UserButtonCode_optLoops] -- add your button handler code here..
        midioptsnode.setProperty("useloops", optLoops->getToggleState(), nullptr);
        //[/UserButtonCode_optLoops]
    }
    else if (buttonThatWasClicked == optMstrVol.get())
    {
        //[UserButtonCode_optMstrVol] -- add your button handler code here..
        midioptsnode.setProperty("addmstrvol", optMstrVol->getToggleState(), nullptr);
        //[/UserButtonCode_optMstrVol]
    }
    else if (buttonThatWasClicked == optExportOrig.get())
    {
        //[UserButtonCode_optExportOrig] -- add your button handler code here..
        if(optExportOrig->getToggleState()){
            midioptsnode.setProperty("exportformat", "original", nullptr);
            optInstDrumCh10->setEnabled(false);
            optInstDrumMulti->setEnabled(false);
        }
        //[/UserButtonCode_optExportOrig]
    }
    else if (buttonThatWasClicked == optExportGM.get())
    {
        //[UserButtonCode_optExportGM] -- add your button handler code here..
        if(optExportGM->getToggleState()){
            midioptsnode.setProperty("exportformat", "generalmidi", nullptr);
            optInstDrumCh10->setEnabled(true);
            optInstDrumMulti->setEnabled(true);
        }
        //[/UserButtonCode_optExportGM]
    }
    else if (buttonThatWasClicked == optInstDrumCh10.get())
    {
        //[UserButtonCode_optInstDrumCh10] -- add your button handler code here..
        if(optInstDrumCh10->getToggleState()) midioptsnode.setProperty("instdrum", "ch10", nullptr);
        //[/UserButtonCode_optInstDrumCh10]
    }
    else if (buttonThatWasClicked == optInstDrumMulti.get())
    {
        //[UserButtonCode_optInstDrumMulti] -- add your button handler code here..
        if(optInstDrumMulti->getToggleState()) midioptsnode.setProperty("instdrum", "multi", nullptr);
        //[/UserButtonCode_optInstDrumMulti]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MidiPane::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == cbxMIDIChnVol.get())
    {
        //[UserComboBoxCode_cbxMIDIChnVol] -- add your combo box handling code here..
        midioptsnode.setProperty("chnvol", cbxMIDIChnVol->getText(), nullptr);
        //[/UserComboBoxCode_cbxMIDIChnVol]
    }
    else if (comboBoxThatHasChanged == cbxMIDIMtrVol.get())
    {
        //[UserComboBoxCode_cbxMIDIMtrVol] -- add your combo box handling code here..
        midioptsnode.setProperty("mtrvol", cbxMIDIMtrVol->getText(), nullptr);
        //[/UserComboBoxCode_cbxMIDIMtrVol]
    }
    else if (comboBoxThatHasChanged == cbxChnPriority.get())
    {
        //[UserComboBoxCode_cbxChnPriority] -- add your combo box handling code here..
        midioptsnode.setProperty("chnpriority", cbxChnPriority->getText(), nullptr);
        //[/UserComboBoxCode_cbxChnPriority]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MidiPane::textEditorTextChanged(TextEditor& editorThatWasChanged){
    int val;
    String text = editorThatWasChanged.getText();
    if(        &editorThatWasChanged == &*txtSeqFormat
            || &editorThatWasChanged == &*txtSeqType
            || &editorThatWasChanged == &*txtMstrVol ){
        val = text.getHexValue32();
    }else{
        val = text.getIntValue();
    }
    bool turnRed = (val <= 0);

    if(&editorThatWasChanged == &*txtMIDIBend){
        midioptsnode.setProperty("bendrange", val, nullptr);
    }else if(&editorThatWasChanged == &*txtMIDIPPQN){
        if(val <= 0) val = 1;
        midioptsnode.setProperty("ppqnmultiplier", val, nullptr);
    }else if(&editorThatWasChanged == &*txtSeqFormat){
        midioptsnode.setProperty("formatbytedefault", val, nullptr);
    }else if(&editorThatWasChanged == &*txtSeqType){
        midioptsnode.setProperty("typebytedefault", val, nullptr);
    }else if(&editorThatWasChanged == &*txtMstrVol){
        midioptsnode.setProperty("addmstrvolval", val, nullptr);
    }else if(&editorThatWasChanged == &*txtStack){
        midioptsnode.setProperty("stacksize", val, nullptr);
    }else if(&editorThatWasChanged == &*txtMergeVels){
        midioptsnode.setProperty("delta_vel", val, nullptr);
    }else if(&editorThatWasChanged == &*txtMergeGates){
        midioptsnode.setProperty("delta_gate", val, nullptr);
    }else if(&editorThatWasChanged == &*txtMergeCCs){
        midioptsnode.setProperty("delta_cc", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQVolT){
        midioptsnode.setProperty("q_vol_time", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQVolA){
        midioptsnode.setProperty("q_vol_amp", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQPitchT){
        midioptsnode.setProperty("q_pitch_time", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQPitchA){
        midioptsnode.setProperty("q_pitch_amp", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQPanT){
        midioptsnode.setProperty("q_pan_time", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQPanA){
        midioptsnode.setProperty("q_pan_amp", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQOtherT){
        midioptsnode.setProperty("q_other_time", val, nullptr);
    }else if(&editorThatWasChanged == &*txtQOtherA){
        midioptsnode.setProperty("q_other_amp", val, nullptr);
    }
    if(turnRed){
        editorThatWasChanged.setColour(TextEditor::backgroundColourId, Colours::red);
    }else{
        editorThatWasChanged.setColour(TextEditor::backgroundColourId, LFWidgetColor());
    }
}


void MidiPane::refreshMIDIControls(){
    midioptsnode = seq64.romdesc.getOrCreateChildWithName("midiopts", nullptr);
    txtMIDIBend->setText(midioptsnode.getProperty("bendrange", 6).toString());
    txtMIDIPPQN->setText(midioptsnode.getProperty("ppqnmultiplier", 4).toString());
    cbxMIDIChnVol->setText(midioptsnode.getProperty("chnvol", "CC7 (Volume)").toString());
    cbxMIDIMtrVol->setText(midioptsnode.getProperty("mtrvol", "CC24 (None)").toString());
    cbxChnPriority->setText(midioptsnode.getProperty("chnpriority", "CC25 (None)").toString());
    txtSeqFormat->setText(ROM::hex((uint8)(int)midioptsnode.getProperty("formatbytedefault", 0x20)));
    txtSeqType->setText(ROM::hex((uint8)(int)midioptsnode.getProperty("typebytedefault", 0x32)));
    txtMstrVol->setText(ROM::hex((uint8)(int)midioptsnode.getProperty("addmstrvolval", 0x58)));
    txtStack->setText(midioptsnode.getProperty("stacksize", 4).toString());
    txtMergeVels->setText(midioptsnode.getProperty("delta_vel", 5).toString());
    txtMergeGates->setText(midioptsnode.getProperty("delta_gate", 3).toString());
    txtMergeCCs->setText(midioptsnode.getProperty("delta_cc", 1).toString());
    txtQVolT->setText(midioptsnode.getProperty("q_vol_time", 0).toString());
    txtQVolA->setText(midioptsnode.getProperty("q_vol_amp", 2).toString());
    txtQPitchT->setText(midioptsnode.getProperty("q_pitch_time", 0).toString());
    txtQPitchA->setText(midioptsnode.getProperty("q_pitch_amp", 1).toString());
    txtQPanT->setText(midioptsnode.getProperty("q_pan_time", 0).toString());
    txtQPanA->setText(midioptsnode.getProperty("q_pan_amp", 2).toString());
    txtQOtherT->setText(midioptsnode.getProperty("q_other_time", 0).toString());
    txtQOtherA->setText(midioptsnode.getProperty("q_other_amp", 1).toString());
    optSeqFormat->setToggleState((bool)midioptsnode.getProperty("writeseqformat", true), dontSendNotification);
    optSeqType->setToggleState((bool)midioptsnode.getProperty("writeseqtype", true), dontSendNotification);
    optChanBits->setToggleState((bool)midioptsnode.getProperty("writechanbits", true), dontSendNotification);
    optMstrVol->setToggleState((bool)midioptsnode.getProperty("addmstrvol", true), dontSendNotification);
    optLoopAll->setToggleState((bool)midioptsnode.getProperty("writeloopall", true), dontSendNotification);
    //optHeader->setToggleState((bool)midioptsnode.getProperty("writeheader", true), dontSendNotification);
    optChanReset->setToggleState((bool)midioptsnode.getProperty("writechanreset", true), dontSendNotification);
    optCalls->setToggleState((bool)midioptsnode.getProperty("usecalls", true), dontSendNotification);
    optLoops->setToggleState((bool)midioptsnode.getProperty("useloops", true), dontSendNotification);
    /*
    String ptrtype = midioptsnode.getProperty("ptrtype", "shortest");
    if(ptrtype == "absolute"){
        optPtrAbsolute->setToggleState(true, dontSendNotification);
    }else if(ptrtype == "relative"){
        optPtrRelative->setToggleState(true, dontSendNotification);
    }else{
        optPtrShortest->setToggleState(true, dontSendNotification);
    }
    */
    bool b = (midioptsnode.getProperty("exportformat", "generalmidi").toString() == "original");
    optExportOrig->setToggleState(b, dontSendNotification);
    optExportGM->setToggleState(!b, dontSendNotification);
    optInstDrumCh10->setEnabled(!b);
    optInstDrumMulti->setEnabled(!b);
    b = (midioptsnode.getProperty("instdrum", "ch10").toString() == "ch10");
    optInstDrumCh10->setToggleState(b, dontSendNotification);
    optInstDrumMulti->setToggleState(!b, dontSendNotification);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiPane" componentName=""
                 parentClasses="public Component, public TextEditor::Listener"
                 constructorParams="SEQ64&amp; seq64_" variableInitialisers="seq64(seq64_)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1078" initialHeight="713">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: 0" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff474747" nonZeroWinding="1">s 32 264 l 32 336 x</PATH>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="d6fd042ed5665f41" memberName="groupComponent8"
                  virtualName="" explicitFocusOrder="0" pos="360 8 352 432" title="Import Settings"/>
  <GROUPCOMPONENT name="new group" id="86dc1328c123b476" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="368 240 336 192" title="Optimization"/>
  <GROUPCOMPONENT name="new group" id="425cb4d36ac8f912" memberName="groupComponent7"
                  virtualName="" explicitFocusOrder="0" pos="0 160 352 192" title="Export Settings"/>
  <GROUPCOMPONENT name="new group" id="41c7820ff71b634e" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 56 352 96" title="Global"/>
  <TEXTBUTTON name="new button" id="3fc9249f7191079e" memberName="btnMIDIExport"
              virtualName="" explicitFocusOrder="0" pos="0 24 176 24" buttonText="Export MIDI"
              connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="deb9b771019f9555" memberName="btnMIDIImport"
              virtualName="" explicitFocusOrder="0" pos="176 24 176 24" buttonText="Import MIDI"
              connectedEdges="1" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="7ee4df75e04ec993" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="8 175 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Bend range:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="f6f8b6c6346a1954" memberName="txtMIDIBend"
              virtualName="" explicitFocusOrder="0" pos="96 175 32 24" initialText="6"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="678cb1b34534af2f" memberName="label21" virtualName=""
         explicitFocusOrder="0" pos="136 175 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="PPQN multiplier:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="99b9654ebd18dc1e" memberName="txtMIDIPPQN"
              virtualName="" explicitFocusOrder="0" pos="248 175 32 24" initialText="2"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="a7e744044efc1585" memberName="label22" virtualName=""
         explicitFocusOrder="0" pos="280 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="x48" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="695e3a0f276fa4e0" memberName="label23" virtualName=""
         explicitFocusOrder="0" pos="8 71 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Chn volume to:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="d119e693727236bb" memberName="cbxMIDIChnVol"
            virtualName="" explicitFocusOrder="0" pos="128 71 216 24" editable="0"
            layout="33" items="CC7 (Volume)&#10;CC11 (Expr)" textWhenNonSelected="ERROR"
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="1dea77f54e15ecb7" memberName="label24" virtualName=""
         explicitFocusOrder="0" pos="8 95 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Master volume to:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="21e08ae5ec6adcb7" memberName="cbxMIDIMtrVol"
            virtualName="" explicitFocusOrder="0" pos="128 95 216 24" editable="0"
            layout="33" items="CC7 (Volume)&#10;CC11 (Expr)&#10;CC16 (GPC1)&#10;CC24 (None)&#10;SysEx MstrVol"
            textWhenNonSelected="ERROR" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="494496a2e6f332ab" memberName="label26" virtualName=""
         explicitFocusOrder="0" pos="8 119 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Chn priority to:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="7007be4d513e8e1c" memberName="cbxChnPriority"
            virtualName="" explicitFocusOrder="0" pos="128 119 216 24" editable="0"
            layout="33" items="CC17 (GPC2)&#10;CC25 (None)&#10;CC79 (SC10)"
            textWhenNonSelected="ERROR" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="new toggle button" id="bea2f7d3365308fd" memberName="optSeqFormat"
                virtualName="" explicitFocusOrder="0" pos="368 24 184 24" buttonText="Create Seq Format cmd:"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="a16780c566945959" memberName="optSeqType"
                virtualName="" explicitFocusOrder="0" pos="368 48 184 24" buttonText="Create Seq Type cmd:"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="d8406232a9779715" memberName="optChanBits"
                virtualName="" explicitFocusOrder="0" pos="368 72 336 24" buttonText="Create Channel Enable/Disable Bitfield Cmds"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="89f530c063ebc41f" memberName="optLoopAll"
                virtualName="" explicitFocusOrder="0" pos="368 120 336 24" buttonText="Create command to loop whole sequence"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="8407bc3e8b8b62f9" memberName="optHeader"
                virtualName="" explicitFocusOrder="0" pos="368 144 336 24" buttonText="Create jump-to-sections header (if sections defined)"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="ebfe7a8ea711aadd" memberName="optChanReset"
                virtualName="" explicitFocusOrder="0" pos="368 168 336 24" buttonText="Initially reset channels"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <GROUPCOMPONENT name="new group" id="3f6e908675196841" memberName="grpPtr" virtualName=""
                  explicitFocusOrder="0" pos="368 192 336 48" title="Pointer Type"/>
  <TOGGLEBUTTON name="new toggle button" id="a704eec5bbb2c46" memberName="optPtrAbsolute"
                virtualName="" explicitFocusOrder="0" pos="464 208 88 24" buttonText="Absolute"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="1bb095294dc9c19d" memberName="optPtrShortest"
                virtualName="" explicitFocusOrder="0" pos="376 208 80 24" buttonText="Shortest"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="1f703315d74170ea" memberName="optPtrRelative"
                virtualName="" explicitFocusOrder="0" pos="552 208 144 24" buttonText="Force Relative Only"
                connectedEdges="0" needsCallback="1" radioGroupId="1" state="0"/>
  <TEXTEDITOR name="new text editor" id="65923cd1adbfea89" memberName="txtSeqFormat"
              virtualName="" explicitFocusOrder="0" pos="560 24 40 24" initialText="20"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="e2cfda96ec6ac80f" memberName="txtSeqType"
              virtualName="" explicitFocusOrder="0" pos="560 48 40 24" initialText="32"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="new toggle button" id="57be9c908829216a" memberName="optCalls"
                virtualName="" explicitFocusOrder="0" pos="376 280 144 24" buttonText="Use Calls"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="f41f0b19ef7d8015" memberName="lblStack"
         virtualName="" explicitFocusOrder="0" pos="376 256 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Stack height:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="2ab348c3ffced623" memberName="txtStack"
              virtualName="" explicitFocusOrder="0" pos="480 256 40 24" initialText="4"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="new toggle button" id="82b4adcc200b6608" memberName="optLoops"
                virtualName="" explicitFocusOrder="0" pos="376 304 144 24" buttonText="Use Loops"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <LABEL name="new label" id="a0db16db13f10260" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="376 328 144 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Merge Even If Off By:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="901a724d96e98e44" memberName="txtMergeVels"
              virtualName="" explicitFocusOrder="0" pos="480 352 40 24" initialText="5"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="e9c365157ee89f96" memberName="txtMergeGates"
              virtualName="" explicitFocusOrder="0" pos="480 376 40 24" initialText="3"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="d3682229a2d89e65" memberName="txtMergeCCs"
              virtualName="" explicitFocusOrder="0" pos="480 400 40 24" initialText="1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="99591c70db040217" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="528 256 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="CC Bandwidth Reduction:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="879d80b64a195ec7" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="528 280 168 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Quantize in: time    ampl" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="1c0cd46f039c823f" memberName="txtQVolT"
              virtualName="" explicitFocusOrder="0" pos="608 304 40 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="edc286004a356a7" memberName="txtQOtherT"
              virtualName="" explicitFocusOrder="0" pos="608 376 40 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="ca751fb5ec03f77b" memberName="txtQVolA"
              virtualName="" explicitFocusOrder="0" pos="656 304 40 24" initialText="2"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="5e72039eac67ea45" memberName="txtQOtherA"
              virtualName="" explicitFocusOrder="0" pos="656 376 40 24" initialText="1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="f28e7ff1efaecfdf" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 0 344 24" edTextCol="ff000000"
         edBkgCol="0" labelText="From/To Audioseq tab:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="38e2b8a24e2c4cf0" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="528 304 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="- Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a46a610ebb27cfc8" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="528 376 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="- Other" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6743b881f0a469a8" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="376 352 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="- Velocities" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="dc9a9cb1e539d990" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="376 376 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="- Gate Times" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="ce10451244d07d82" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="376 400 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="- CCs" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="e3e7d963da09a087" memberName="txtQPitchT"
              virtualName="" explicitFocusOrder="0" pos="608 328 40 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="ef6d5b29efe67c05" memberName="txtQPitchA"
              virtualName="" explicitFocusOrder="0" pos="656 328 40 24" initialText="1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="c1807deff329fd4b" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="528 328 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="- Pitch" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="4bc5598877271b87" memberName="txtQPanT"
              virtualName="" explicitFocusOrder="0" pos="608 352 40 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="591164d5daf46f21" memberName="txtQPanA"
              virtualName="" explicitFocusOrder="0" pos="656 352 40 24" initialText="2"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="7b14856ae0061bca" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="528 352 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="- Pan/FX" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="2481ecc07a4e97d4" memberName="optMstrVol"
                virtualName="" explicitFocusOrder="0" pos="368 96 272 24" buttonText="Add Master Volume cmd if not in MIDI: "
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTEDITOR name="new text editor" id="331980c066cb2712" memberName="txtMstrVol"
              virtualName="" explicitFocusOrder="0" pos="640 96 40 24" initialText="58"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <GROUPCOMPONENT name="new group" id="5df674d8db14913d" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 200 336 144" title="Export Format"/>
  <TOGGLEBUTTON name="new toggle button" id="bda773c823cc5c97" memberName="optExportOrig"
                virtualName="" explicitFocusOrder="0" pos="16 216 320 24" buttonText="Original (for edit + re-import)"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="472c8df3c73c370e" memberName="optExportGM"
                virtualName="" explicitFocusOrder="0" pos="16 240 320 24" buttonText="General MIDI (for playback)"
                connectedEdges="0" needsCallback="1" radioGroupId="2" state="1"/>
  <LABEL name="new label" id="a5db09094d06d038" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="32 264 304 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Instrument to drums:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="f417d14c6e503f9a" memberName="optInstDrumCh10"
                virtualName="" explicitFocusOrder="0" pos="40 288 296 24" buttonText="Force Ch. 10 (more compatible, less accurate)"
                connectedEdges="0" needsCallback="1" radioGroupId="3" state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="2c5743413725081d" memberName="optInstDrumMulti"
                virtualName="" explicitFocusOrder="0" pos="40 312 296 24" buttonText="Many Drum Chns Hack (less compatible)"
                connectedEdges="0" needsCallback="1" radioGroupId="3" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
