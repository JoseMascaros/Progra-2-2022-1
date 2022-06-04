#pragma once
#include "Hero.h"

namespace SpritesWeek {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

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

		//Bitmap
		Bitmap^ bmpHero;
		Bitmap^ bmpMap;

		//SoundPlayer
		SoundPlayer^ spTheme;

		//Hero
		Hero* hero;

	public:
		FrmMain(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Bitmap
			bmpHero = gcnew Bitmap("gold.png");
			bmpMap = gcnew Bitmap("fondo.png");

			//SoundPlayer
			spTheme = gcnew SoundPlayer("music.wav");

			//Hero
			hero = new Hero(bmpHero->Width / 4, bmpHero->Height / 4);

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1105, 648);
			this->panel1->TabIndex = 0;
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
			this->ClientSize = System::Drawing::Size(1111, 653);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Erase
		buffer->Graphics->Clear(Color::WhiteSmoke);
		//Move
		//Draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, panel1->Width, panel1->Height);
		hero->draw(buffer->Graphics, bmpHero);
		//Render
		buffer->Render(g);
	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			hero->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			hero->move(buffer->Graphics, 'D'); break;
		case Keys::W:
			hero->move(buffer->Graphics, 'W'); break;
		case Keys::S:
			hero->move(buffer->Graphics, 'S'); break;
		case Keys::P:
			bmpHero = gcnew Bitmap("pikachu.png"); 
			bmpHero->MakeTransparent(bmpHero->GetPixel(0,0));
			break;
		}
	}
	private: System::Void FrmMain_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		hero->still();
	}
private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	spTheme->PlayLooping();
}
};
}
