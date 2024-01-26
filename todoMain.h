// Header file for the TForm1 class
#ifndef todoMainH
#define todoMainH
//---------------------------------------------------------------------------
// Include the necessary header files
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <fstream> // This is needed for the file input/output operations
//---------------------------------------------------------------------------
// Declare the TForm1 class, which inherits from the TForm class
class TForm1 : public TForm
{
__published:    // IDE-managed Components
    // Declare the UI components of the form
    TLabel *HeaderLabel;
    TEdit *InputField;
    TButton *AddButton;
    TListBox *OutputField;
    // Declare the event handlers for the UI components
    void __fastcall AddButtonClick(TObject *Sender);
    void __fastcall OutputFieldItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);

private:    // User declarations
	// Declare the private functions for loading and saving tasks
    void __fastcall LoadTasks();
	void __fastcall SaveTasks();

public:        // User declarations
    // Declare the constructor for the form
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
// Declare the global variable Form1, which is an instance of the TForm1 class
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

