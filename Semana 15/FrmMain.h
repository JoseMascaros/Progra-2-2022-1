#pragma once
#include "Controller.h"
#include "File.h"

namespace MiniPokemonGame {

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
		//File
		File* file;

		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmaps
		Bitmap^ bmpPikachu;
		Bitmap^ bmpPokeball;
		Bitmap^ bmpMap;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblHP;
	private: System::Windows::Forms::Label^ label1;

		//Controller
		Controller* controller;
	private: System::Windows::Forms::Timer^ timerTime;

		//Time
		int gtime;

	public:
		FrmMain(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//File
			file = new File();

			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmaps
			bmpPikachu = gcnew Bitmap("pikachu.png");
			bmpPikachu->MakeTransparent(bmpPikachu->GetPixel(0, 0));
			bmpPokeball = gcnew Bitmap("pokeball.png");
			bmpMap = gcnew Bitmap("fondo.png");

			//Time
			gtime = file->getGTime();

			//Controller
			controller = new Controller(file->getX(), file->getY(), bmpPikachu, file->getHp(), bmpPokeball);
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
	private: System::Windows::Forms::Timer^ timerMain;
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
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblHP = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lblTime);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->lblHP);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(959, 894);
			this->panel1->TabIndex = 0;
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Location = System::Drawing::Point(852, 23);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(16, 17);
			this->lblTime->TabIndex = 3;
			this->lblTime->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(803, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Time:";
			// 
			// lblHP
			// 
			this->lblHP->AutoSize = true;
			this->lblHP->Location = System::Drawing::Point(125, 23);
			this->lblHP->Name = L"lblHP";
			this->lblHP->Size = System::Drawing::Size(16, 17);
			this->lblHP->TabIndex = 1;
			this->lblHP->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Health Points:";
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &FrmMain::timerMain_Tick);
			// 
			// timerTime
			// 
			this->timerTime->Enabled = true;
			this->timerTime->Interval = 1000;
			this->timerTime->Tick += gcnew System::EventHandler(this, &FrmMain::timerTime_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 891);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Collision
		controller->collision();
		//Move
		controller->moveEverything(buffer->Graphics);
		//Draw
		lblTime->Text = Convert::ToString(gtime);
		lblHP->Text = Convert::ToString(controller->getPikachu()->getHp());
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		controller->drawEverything(buffer->Graphics, bmpPikachu, bmpPokeball);
		//Render
		if (controller->getPikachu()->getHp() <= 0) {
			timerMain->Enabled = false;
			timerTime->Enabled = false;
			MessageBox::Show("You Lose");
			this->Close();
		}
		else if (gtime <= 0) {
			timerMain->Enabled = false;
			timerTime->Enabled = false;
			MessageBox::Show("You Win");
			this->Close();
		}
		else {
			buffer->Render(g);
		}
		
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Left: case Keys::A:
			controller->getPikachu()->move(buffer->Graphics, 'A'); break;
		case Keys::Right: case Keys::D:
			controller->getPikachu()->move(buffer->Graphics, 'D'); break;
		case Keys::Up: case Keys::W:
			controller->getPikachu()->move(buffer->Graphics, 'W'); break;
		case Keys::Down: case Keys::S:
			controller->getPikachu()->move(buffer->Graphics, 'S'); break;
		}
	}
private: System::Void timerTime_Tick(System::Object^ sender, System::EventArgs^ e) {
	gtime--;
}
};
}
