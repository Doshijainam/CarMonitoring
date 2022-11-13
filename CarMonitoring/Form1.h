#pragma once
#include "Functions.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ volumeUp;
	protected:
	private: System::Windows::Forms::Label^ volumeDown;
	private: System::Windows::Forms::Label^ currentVolume;
	private: System::Windows::Forms::TextBox^ displayCurrentVolume;
	private: System::Windows::Forms::Button^ volumeUpButton;
	private: System::Windows::Forms::Button^ volumeDownButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->volumeUp = (gcnew System::Windows::Forms::Label());
			this->volumeDown = (gcnew System::Windows::Forms::Label());
			this->currentVolume = (gcnew System::Windows::Forms::Label());
			this->displayCurrentVolume = (gcnew System::Windows::Forms::TextBox());
			this->volumeUpButton = (gcnew System::Windows::Forms::Button());
			this->volumeDownButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// volumeUp
			// 
			this->volumeUp->AutoSize = true;
			this->volumeUp->Location = System::Drawing::Point(23, 151);
			this->volumeUp->Name = L"volumeUp";
			this->volumeUp->Size = System::Drawing::Size(74, 16);
			this->volumeUp->TabIndex = 0;
			this->volumeUp->Text = L"Volume Up";
			// 
			// volumeDown
			// 
			this->volumeDown->AutoSize = true;
			this->volumeDown->Location = System::Drawing::Point(23, 240);
			this->volumeDown->Name = L"volumeDown";
			this->volumeDown->Size = System::Drawing::Size(90, 16);
			this->volumeDown->TabIndex = 1;
			this->volumeDown->Text = L"Volume Down";
			// 
			// currentVolume
			// 
			this->currentVolume->AutoSize = true;
			this->currentVolume->Location = System::Drawing::Point(437, 151);
			this->currentVolume->Name = L"currentVolume";
			this->currentVolume->Size = System::Drawing::Size(98, 16);
			this->currentVolume->TabIndex = 2;
			this->currentVolume->Text = L"Current Volume";
			// 
			// displayCurrentVolume
			// 
			this->displayCurrentVolume->Location = System::Drawing::Point(412, 184);
			this->displayCurrentVolume->Name = L"displayCurrentVolume";
			this->displayCurrentVolume->Size = System::Drawing::Size(144, 22);
			this->displayCurrentVolume->TabIndex = 3;
			this->displayCurrentVolume->Text = L"0";
			this->displayCurrentVolume->TextChanged += gcnew System::EventHandler(this, &Form1::displayCurrentVolume_TextChanged);
			// 
			// volumeUpButton
			// 
			this->volumeUpButton->Location = System::Drawing::Point(26, 171);
			this->volumeUpButton->Name = L"volumeUpButton";
			this->volumeUpButton->Size = System::Drawing::Size(75, 23);
			this->volumeUpButton->TabIndex = 4;
			this->volumeUpButton->Text = L"Increase";
			this->volumeUpButton->UseVisualStyleBackColor = true;
			this->volumeUpButton->Click += gcnew System::EventHandler(this, &Form1::volumeUpButton_Click);
			// 
			// volumeDownButton
			// 
			this->volumeDownButton->Location = System::Drawing::Point(26, 260);
			this->volumeDownButton->Name = L"volumeDownButton";
			this->volumeDownButton->Size = System::Drawing::Size(75, 23);
			this->volumeDownButton->TabIndex = 5;
			this->volumeDownButton->Text = L"Decrease";
			this->volumeDownButton->UseVisualStyleBackColor = true;
			this->volumeDownButton->Click += gcnew System::EventHandler(this, &Form1::volumeDownButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(586, 461);
			this->Controls->Add(this->volumeDownButton);
			this->Controls->Add(this->volumeUpButton);
			this->Controls->Add(this->displayCurrentVolume);
			this->Controls->Add(this->currentVolume);
			this->Controls->Add(this->volumeDown);
			this->Controls->Add(this->volumeUp);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void volumeUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int currentVolume = Convert::ToInt32(displayCurrentVolume->Text);
		int result = incrementVolume(currentVolume);
		displayCurrentVolume->Clear();
		displayCurrentVolume->AppendText(String::Format("{0}\r", result));

	}
private: System::Void displayCurrentVolume_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void volumeDownButton_Click(System::Object^ sender, System::EventArgs^ e) {


	int currentVolume = Convert::ToInt32(displayCurrentVolume->Text);
	int result = decrementVolume(currentVolume);
	if (result = 0)
	{
		displayCurrentVolume->Clear();
		displayCurrentVolume->AppendText(String::Format("{0}\r", 0));
	}
}
};
}
