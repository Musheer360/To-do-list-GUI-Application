#include <fmx.h>
#include <System.IOUtils.hpp>
#include <fstream> // This is needed for file I/O operations
#include <string> // This is needed for the String class

//---------------------------------------------------------------------------
#pragma hdrstop
#include "todoMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Windows.fmx", _PLAT_MSWINDOWS)
#pragma resource ("*.Surface.fmx", _PLAT_MSWINDOWS)

TForm1 *Form1;

//---------------------------------------------------------------------------
// Constructor: initialize the form and load the tasks from a file
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    LoadTasks();
}

//---------------------------------------------------------------------------
// Event handler: add a new task to the list and save it to a file
void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
    String taskText = InputField->Text;

    // Check if the input is not empty
    if(taskText.IsEmpty()) {
		return;
	}

    // Add the task to the output field
    OutputField->Items->Add(" - " + taskText);
    // Clear the input field
    InputField->Text = "";

    // Append the task to the file
    std::wofstream file("C:\\Windows\\Temp\\todoitems.txt", std::ios::app);

    if (file.is_open()) {
        file << taskText.c_str() << std::endl;
		file.close();
    }
}

//---------------------------------------------------------------------------
// Event handler: delete a task from the list and save the changes to a file
void __fastcall TForm1::OutputFieldItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)
{
    int itemIndex = Item->Index;
	OutputField->Items->Delete(itemIndex);

    SaveTasks();
}

//---------------------------------------------------------------------------
// Function: load the tasks from a file and display them in the output field
void __fastcall TForm1::LoadTasks()
{
    TStringList *tasks = new TStringList;
    std::wifstream file("C:\\Windows\\Temp\\todoitems.txt");
    if (file.is_open()) {
        std::wstring line;
        while (std::getline(file, line)) {
            // Add " - " before each line and then add it to the tasks list
            tasks->Add((L" - " + line).c_str());
        }
        file.close();
        OutputField->Items->Assign(tasks);
    }
    delete tasks;
}

//---------------------------------------------------------------------------
// Function: save the tasks from the output field to a file
void __fastcall TForm1::SaveTasks()
{
	TStringList *tasks = new TStringList;
	tasks->Assign(OutputField->Items);

	// Overwrite the file with the tasks list
	std::wofstream file("C:\\Windows\\Temp\\todoitems.txt");
    if (file.is_open()) {
        for (int i = 0; i < tasks->Count; ++i) {
            file << L" - " << tasks->Strings[i].c_str() << std::endl;
		}
        file.close();
	}

	delete tasks;
}



