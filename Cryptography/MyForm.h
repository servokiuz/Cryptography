#include "Kuznechik.h"


#pragma once

std::string fileName;
uint8_t key[32];

namespace Cryptography {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(522, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(225, 20);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выбрать файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(71, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(676, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ключ:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Файл:";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(15, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(343, 51);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Зашифровать файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(404, 75);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(343, 51);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Расшифровать файл";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(68, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(10, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"-";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(759, 137);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Zuikov 20IP1b Diplom";
			this->ResumeLayout(false);
			this->PerformLayout();

		}



#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				System::String^ fName = openFileDialog1->FileName;
				label3->Text = fName;
				
				fileName.resize(fName->Length);
				char *text= new char[fName->Length];
				for (size_t i = 0; i < fName->Length; i++)
				{
					fileName[i] = fName[i];
					text[i] = fName[i];

				}
				for (size_t i = 0; i < 32; i++)
				{
					if (textBox1->Text[i * 2] == 'a' || textBox1->Text[i * 2] == 'b' ||
						textBox1->Text[i * 2] == 'c' || textBox1->Text[i * 2] == 'd' ||
						textBox1->Text[i * 2] == 'e' || textBox1->Text[i * 2] == 'f' ||
						textBox1->Text[i * 2 + 1] == 'a' || textBox1->Text[i * 2 + 1] == 'b' ||
						textBox1->Text[i * 2 + 1] == 'c' || textBox1->Text[i * 2 + 1] == 'd' ||
						textBox1->Text[i * 2 + 1] == 'e' || textBox1->Text[i * 2 + 1] == 'f' )

						key[i] = ((int)(textBox1->Text[i * 2]) - 87) * 16 + ((int)(textBox1->Text[i * 2 + 1]) - 87);
					else
						if (textBox1->Text[i * 2] == 'A' || textBox1->Text[i * 2] == 'B' ||
							textBox1->Text[i * 2] == 'c' || textBox1->Text[i * 2] == 'd' ||
							textBox1->Text[i * 2] == 'e' || textBox1->Text[i * 2] == 'f' ||
							textBox1->Text[i * 2 + 1] == 'a' || textBox1->Text[i * 2 + 1] == 'b' ||
							textBox1->Text[i * 2 + 1] == 'c' || textBox1->Text[i * 2 + 1] == 'd' ||
							textBox1->Text[i * 2 + 1] == 'e' || textBox1->Text[i * 2 + 1] == 'f')
							key[i] = ((int)(textBox1->Text[i * 2]) - 55) * 16 + ((int)(textBox1->Text[i * 2 + 1]) - 55);
						else
							key[i] = ((int)(textBox1->Text[i * 2]) - '0') * 16 + ((int)(textBox1->Text[i * 2 + 1]) - '0');

				}
				myStream->Close();
			}
		}

	}
	
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {//enc
	alg_Kuznechik(fileName,key, 1);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {//dec
	alg_Kuznechik(fileName,key, 2);
}
};
}
