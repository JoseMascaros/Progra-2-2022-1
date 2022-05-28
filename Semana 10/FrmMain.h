#pragma once
#include "Controller.h"

namespace DrawingFigures2022 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ pictureBoxColor;
	private: System::Windows::Forms::TextBox^ txbB;
	private: System::Windows::Forms::TextBox^ txbG;
	private: System::Windows::Forms::TextBox^ txbR;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

		//Controller
		Controller* controller;

	public:
		FrmMain(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Controller
			controller = new Controller();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBoxColor = (gcnew System::Windows::Forms::PictureBox());
			this->txbB = (gcnew System::Windows::Forms::TextBox());
			this->txbG = (gcnew System::Windows::Forms::TextBox());
			this->txbR = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxColor))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Location = System::Drawing::Point(2, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(999, 617);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMain::panel1_MouseClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->pictureBoxColor);
			this->groupBox1->Controls->Add(this->txbB);
			this->groupBox1->Controls->Add(this->txbG);
			this->groupBox1->Controls->Add(this->txbR);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(347, 135);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Color";
			// 
			// pictureBoxColor
			// 
			this->pictureBoxColor->Location = System::Drawing::Point(175, 21);
			this->pictureBoxColor->Name = L"pictureBoxColor";
			this->pictureBoxColor->Size = System::Drawing::Size(166, 104);
			this->pictureBoxColor->TabIndex = 6;
			this->pictureBoxColor->TabStop = false;
			// 
			// txbB
			// 
			this->txbB->Location = System::Drawing::Point(50, 101);
			this->txbB->Name = L"txbB";
			this->txbB->Size = System::Drawing::Size(98, 22);
			this->txbB->TabIndex = 5;
			this->txbB->TextChanged += gcnew System::EventHandler(this, &FrmMain::txbB_TextChanged);
			// 
			// txbG
			// 
			this->txbG->Location = System::Drawing::Point(50, 67);
			this->txbG->Name = L"txbG";
			this->txbG->Size = System::Drawing::Size(98, 22);
			this->txbG->TabIndex = 4;
			this->txbG->TextChanged += gcnew System::EventHandler(this, &FrmMain::txbG_TextChanged);
			// 
			// txbR
			// 
			this->txbR->Location = System::Drawing::Point(49, 33);
			this->txbR->Name = L"txbR";
			this->txbR->Size = System::Drawing::Size(98, 22);
			this->txbR->TabIndex = 3;
			this->txbR->TextChanged += gcnew System::EventHandler(this, &FrmMain::txbR_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"B";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"G";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"R";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmMain::timer1_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1004, 620);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->panel1->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxColor))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Erase
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Move
		controller->moveEverything(buffer->Graphics);
		//Draw
		controller->drawEverything(buffer->Graphics);
		//Render
		buffer->Render(g);
	}

	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::T:
			controller->deleteTriangle(); break;
		case Keys::C:
			controller->deleteCircle(); break;
		case Keys::Q:
			controller->deleteSquare(); break;
		}
	}
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			int r = rand() % 3;
			switch (r)
			{
			case 0: controller->addTriangle(e->X, e->Y, Convert::ToInt32(txbR->Text), Convert::ToInt32(txbG->Text), Convert::ToInt32(txbB->Text)); break;
			case 1: controller->addCircle(e->X, e->Y, Convert::ToInt32(txbR->Text), Convert::ToInt32(txbG->Text), Convert::ToInt32(txbB->Text)); break;
			case 2: controller->addSquare(e->X, e->Y, Convert::ToInt32(txbR->Text), Convert::ToInt32(txbG->Text), Convert::ToInt32(txbB->Text)); break;
			}
		}
	}
private: System::Void txbR_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (txbR->Text != "" && txbG->Text != "" && txbB->Text != "") {
		pictureBoxColor->BackColor = Color::FromArgb(Convert::ToInt32(txbR->Text), Convert::ToInt32(txbG->Text), Convert::ToInt32(txbB->Text));
	}
}
private: System::Void txbG_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (txbR->Text != "" && txbG->Text != "" && txbB->Text != "") {
		pictureBoxColor->BackColor = Color::FromArgb(Convert::ToInt32(txbR->Text), Convert::ToInt32(txbG->Text), Convert::ToInt32(txbB->Text));
	}
}
private: System::Void txbB_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (txbR->Text != "" && txbG->Text != "" && txbB->Text != "") {
		pictureBoxColor->BackColor = Color::FromArgb(Convert::ToInt32(txbR->Text), Convert::ToInt32(txbG->Text), Convert::ToInt32(txbB->Text));
	}
}
};
}
