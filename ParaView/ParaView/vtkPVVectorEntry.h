/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPVVectorEntry.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2000-2001 Kitware Inc. 469 Clifton Corporate Parkway,
Clifton Park, NY, 12065, USA.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither the name of Kitware nor the names of any contributors may be used
   to endorse or promote products derived from this software without specific 
   prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
// .NAME vtkPVVectorEntry -
// .SECTION Description

#ifndef __vtkPVVectorEntry_h
#define __vtkPVVectorEntry_h

#include "vtkPVObjectWidget.h"
#include "vtkKWApplication.h"
#include "vtkKWLabel.h"
#include "vtkKWWidgetCollection.h"

class VTK_EXPORT vtkPVVectorEntry : public vtkPVObjectWidget
{
public:
  static vtkPVVectorEntry* New();
  vtkTypeMacro(vtkPVVectorEntry, vtkPVObjectWidget);

  void Create(vtkKWApplication *pvApp, char *label, int vectorLength,
              char **subLabels, char *help);
  
  // Description:
  // Called when accept button is pushed.  
  // Sets objects variable to the widgets value.
  // Adds a trace entry.  Side effect is to turn modified flag off.
  virtual void Accept();
  
  // Description:
  // Called when the reset button is pushed.
  // Sets widget's value to the object-variable's value.
  // Side effect is to turn the modified flag off.
  virtual void Reset();

  // Description:
  // I will eventually remove access to internal widgets once I figure
  // out how to get the vectors value in Tcl with any number of componenets.
  vtkGetObjectMacro(Label, vtkKWLabel);
  vtkGetObjectMacro(SubLabels, vtkKWWidgetCollection);
  vtkGetObjectMacro(Entries, vtkKWWidgetCollection);
  vtkKWLabel* GetSubLabel(int idx);
  vtkKWEntry* GetEntry(int idx);

  // Description:
  // Methods to set this widgets value from a script.
  void SetValue(char* v);
  void SetValue(char* v1, char* v2);
  void SetValue(char* v1, char* v2, char* v3);
  void SetValue(char* v1, char* v2, char* v3, char* v4);
  void SetValue(char* v1, char* v2, char* v3, char* v4, char* v5);
  void SetValue(char* v1, char* v2, char* v3, char* v4, char* v5, char* v6);
  void SetValue(char** vals, int num);
  
  // Description:
  // I need a solution:  I want to run ParaView with a low resolution
  // data set, but create a batch simulation with high resolution data.
  //  When this widget is saved in a VTK script, this value is used.
  vtkSetStringMacro(ScriptValue);
  vtkGetStringMacro(ScriptValue);

  // Description:
  // An interface for saving a widget into a script.
  virtual void SaveInTclScript(ofstream *file);

protected:
  vtkPVVectorEntry();
  ~vtkPVVectorEntry();
  vtkPVVectorEntry(const vtkPVVectorEntry&) {};
  void operator=(const vtkPVVectorEntry&) {};
  
  vtkKWLabel *Label;
  vtkKWWidgetCollection *SubLabels;
  vtkKWWidgetCollection *Entries;

  char *ScriptValue;
};

#endif
