#pragma once
#include "Test.h"
#include "mainTask.h"
#include <chrono>


namespace SimpleIterations {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::Button^ ��������;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ ��������;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->�������� = (gcnew System::Windows::Forms::Button());
			this->�������� = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1377, 614);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->��������);
			this->tabPage1->Controls->Add(this->��������);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabPage1->Size = System::Drawing::Size(1369, 588);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"������� ����";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(111, 190);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"�������� ���";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(21, 183);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(76, 20);
			this->textBox5->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(111, 146);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"������� �������� N_max";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(111, 105);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"������� ��������� ��������";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(111, 68);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"������� ����� m";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(111, 34);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"������� ����� n";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.5F));
			this->label1->Location = System::Drawing::Point(315, 30);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"label1";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(21, 142);
			this->textBox4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(76, 20);
			this->textBox4->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(21, 101);
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(21, 64);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(21, 30);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// ��������
			// 
			this->��������->Location = System::Drawing::Point(33, 292);
			this->��������->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->��������->Name = L"��������";
			this->��������->Size = System::Drawing::Size(130, 34);
			this->��������->TabIndex = 1;
			this->��������->Text = L"�������� ������";
			this->��������->UseVisualStyleBackColor = true;
			this->��������->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// ��������
			// 
			this->��������->Location = System::Drawing::Point(33, 227);
			this->��������->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->��������->Name = L"��������";
			this->��������->Size = System::Drawing::Size(130, 34);
			this->��������->TabIndex = 0;
			this->��������->Text = L"�������� ������";
			this->��������->UseVisualStyleBackColor = true;
			this->��������->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabPage2->Size = System::Drawing::Size(1369, 588);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"��������� �������";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(17, 20);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1337, 552);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			this->dataGridView1->ColumnAdded += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &MyForm::dataGridView1_ColumnAdded);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1369, 588);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"������ �������";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(7, 14);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(1357, 571);
			this->dataGridView2->TabIndex = 0;
			this->dataGridView2->ColumnAdded += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &MyForm::dataGridView2_ColumnAdded);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->dataGridView3);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(1369, 588);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"��������";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(7, 12);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(1357, 573);
			this->dataGridView3->TabIndex = 0;
			this->dataGridView3->ColumnAdded += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &MyForm::dataGridView3_ColumnAdded);
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Size = System::Drawing::Size(1369, 588);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"�������";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1283, 614);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	const std::clock_t c_start = std::clock();
	auto t_start = std::chrono::high_resolution_clock::now();
	int N = System::Convert::ToInt32(textBox1->Text);
	int M = System::Convert::ToInt32(textBox2->Text);
	double eps = Convert::ToDouble(textBox3->Text);
	int Nmax = System::Convert::ToInt64(textBox4->Text);
	double tau = Convert::ToDouble(textBox5->Text);
	//int K = System::Convert::ToInt64(textBox5->Text);

	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	dataGridView1->Refresh();
	dataGridView1->ColumnCount = N + 3;
	dataGridView1->RowCount = M + 3;
	dataGridView1->Columns[0]->DefaultCellStyle->Format = "n2";
	dataGridView2->Rows->Clear();
	dataGridView2->Columns->Clear();
	dataGridView2->Refresh();
	dataGridView2->ColumnCount = N + 3;
	dataGridView2->RowCount = M + 3;
	dataGridView3->Rows->Clear();
	dataGridView3->Columns->Clear();
	dataGridView3->Refresh();
	dataGridView3->ColumnCount = N + 3;
	dataGridView3->RowCount = M + 3;
	double Eps_max = 0.0;
	int index = 0;
	double temp2 = 0.0;
	double MaxF = 0.0;
	for (int i = 0; i < N + 1; i++) {
		dataGridView2->Rows[0]->Cells[i + 2]->Value = 2 * i * 1.0 / N;
		dataGridView2->Rows[1]->Cells[i + 2]->Value = i;
	}
	for (int j = 0; j < M + 1; j++) {
		dataGridView2->Rows[j + 2]->Cells[0]->Value = j * 1.0 / M;
		dataGridView2->Rows[j + 2]->Cells[1]->Value = j;
	}
	dataGridView2->Rows[0]->Cells[1]->Value = gcnew String("x");
	dataGridView2->Rows[1]->Cells[0]->Value = gcnew String("y");
	dataGridView2->Rows[1]->Cells[1]->Value = gcnew String("j/i");
	for (int i = 0; i < N + 1; i++) {
		dataGridView1->Rows[0]->Cells[i + 2]->Value = 2 * i * 1.0 / N;
		dataGridView1->Rows[1]->Cells[i + 2]->Value = i;
	}
	for (int j = 0; j < M + 1; j++) {
		dataGridView1->Rows[j + 2]->Cells[0]->Value = j * 1.0 / M;
		dataGridView1->Rows[j + 2]->Cells[1]->Value = j;
	}
	dataGridView1->Rows[0]->Cells[1]->Value = gcnew String("x");
	dataGridView1->Rows[1]->Cells[0]->Value = gcnew String("y");
	dataGridView1->Rows[1]->Cells[1]->Value = gcnew String("j/i");
	double** f1 = U(N, M, 0, 2, 0, 1);
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < M + 1; j++) {
			dataGridView2->Rows[j + 2]->Cells[i + 2]->Value = floor(f1[i][j]*1000)/1000;
			double xPoint = 2 * i * 1.0 / N;
			double yPoint = j * 1.0 / M;
		}
	}
	double** v = mpiTest(N, M, 0, 2, 0, 1, Nmax, eps, Eps_max, index, temp2, MaxF, tau, f1);
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < M + 1; j++) {
			dataGridView1->Rows[j + 2]->Cells[i + 2]->Value = floor(v[i][j] * 1000) / 1000;
		}
	}
	dataGridView3->Rows->Clear();
	dataGridView3->Columns->Clear();
	dataGridView3->Refresh();
	dataGridView3->ColumnCount = N + 3;
	dataGridView3->RowCount = M + 3;
	for (int i = 0; i < N + 1; i++) {
		dataGridView3->Rows[0]->Cells[i + 2]->Value = 2 * i * 1.0 / N;
		dataGridView3->Rows[1]->Cells[i + 2]->Value = i;
	}
	for (int j = 0; j < M + 1; j++) {
		dataGridView3->Rows[j + 2]->Cells[0]->Value = j * 1.0 / M;
		dataGridView3->Rows[j + 2]->Cells[1]->Value = j;
	}
	dataGridView3->Rows[0]->Cells[1]->Value = gcnew String("x");
	dataGridView3->Rows[1]->Cells[0]->Value = gcnew String("y");
	dataGridView3->Rows[1]->Cells[1]->Value = gcnew String("j/i");
	double max = 0;
	double x = 0;
	double y = 0;

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < M + 1; j++) {
			double z = abs(v[i][j] - f1[i][j]);
			dataGridView3->Rows[j + 2]->Cells[i + 2]->Value = z;
			if (z > max) {
				max = z;
				x = 0 + j * 1.0 / M;
				y = i * 1.0 / N;
			}
		}
	}

	const std::clock_t c_end = std::clock();
	const auto t_end = std::chrono::high_resolution_clock::now();
	label1->Text = "\n ���-�� �����: " + System::Convert::ToString(index) +
		"\n ����������� ��������: " + System::Convert::ToString(Eps_max) +
		"\n ����������� ������� U-V: " + System::Convert::ToString(max) +
		"\n �������� Tau: " + System::Convert::ToString(tau) +
		"\n �����: " + System::Convert::ToString((c_end - c_start) / CLOCKS_PER_SEC) + "s\n";
		"\n ������� ���� �� ���. ����������� R(0): " + System::Convert::ToString(MaxF) +
		"\n ������� ���� �� ������ R(p): " + System::Convert::ToString(abs(temp2));


}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	const std::clock_t c_start = std::clock();
	auto t_start = std::chrono::high_resolution_clock::now();
	int N = System::Convert::ToInt64(textBox1->Text);
	int M = System::Convert::ToInt64(textBox2->Text);
	double eps = Convert::ToDouble(textBox3->Text);
	int Nmax = System::Convert::ToInt64(textBox4->Text);
	const double tau = Convert::ToDouble(textBox5->Text);
	double MaxR1 = 0.0;
	double MaxR2 = 0.0;
	//double K = Convert::ToDouble(textBox5->Text);

	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	dataGridView1->Refresh();
	dataGridView1->ColumnCount = 2*N + 3;
	dataGridView1->RowCount = 2*M + 3;
	dataGridView1->Columns[0]->DefaultCellStyle->Format = "n2";
	dataGridView2->Rows->Clear();
	dataGridView2->Columns->Clear();
	dataGridView2->Refresh();
	dataGridView2->ColumnCount = N + 3;
	dataGridView2->RowCount = M + 3;
	dataGridView3->Rows->Clear();
	dataGridView3->Columns->Clear();
	dataGridView3->Refresh();
	dataGridView3->ColumnCount = N + 3;
	dataGridView3->RowCount = M + 3;
	double Eps_max2 = 0.0;
	int index2 = 0;
	double temp22 = 0.0;
	double MaxF2 = 0.0;
	for (int i = 0; i < 2*N + 1; i++) {
		dataGridView1->Rows[0]->Cells[i + 2]->Value = 2 * i * 1.0 / (2*N);
		dataGridView1->Rows[1]->Cells[i + 2]->Value = i;
	}
	for (int j = 0; j < 2*M + 1; j++) {
		dataGridView1->Rows[j + 2]->Cells[0]->Value = j * 1.0 / (2*M);
		dataGridView1->Rows[j + 2]->Cells[1]->Value = j;
	}
	dataGridView1->Rows[0]->Cells[1]->Value = gcnew String("x");
	dataGridView1->Rows[1]->Cells[0]->Value = gcnew String("y");
	dataGridView1->Rows[1]->Cells[1]->Value = gcnew String("j/i");
	double** v22 = mpiMain2(2*N, 2*M, 0, 2, 0, 1, Nmax, eps, Eps_max2, index2, temp22, MaxF2, tau, MaxR2);
	for (int i = 0; i < 2*N + 1; i++) {
		for (int j = 0; j < 2*M + 1; j++) {
			dataGridView1->Rows[j + 2]->Cells[i + 2]->Value = floor(v22[i][j]*1000)/1000;
			double xPoint = 2 * i * 1.0 / N;
			double yPoint = j * 1.0 / M;
		}
	}
	double Eps_max = 0.0;
	int index = 0;
	double temp2 = 0.0;
	double MaxF = 0.0;
	for (int i = 0; i < N + 1; i++) {
		dataGridView2->Rows[0]->Cells[i + 2]->Value = 2 * i * 1.0 / N;
		dataGridView2->Rows[1]->Cells[i + 2]->Value = i;
	}
	for (int j = 0; j < M + 1; j++) {
		dataGridView2->Rows[j + 2]->Cells[0]->Value = j * 1.0 / M;
		dataGridView2->Rows[j + 2]->Cells[1]->Value = j;
	}
	dataGridView2->Rows[0]->Cells[1]->Value = gcnew String("x");
	dataGridView2->Rows[1]->Cells[0]->Value = gcnew String("y");
	dataGridView2->Rows[1]->Cells[1]->Value = gcnew String("j/i");
	double** v2 = mpiMain(N, M, 0, 2, 0, 1, Nmax, eps, Eps_max, index, temp2, MaxF, tau, MaxR1);
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < M + 1; j++) {
			dataGridView2->Rows[j + 2]->Cells[i + 2]->Value = floor(v2[i][j]*1000)/1000;
		}
	}
	dataGridView3->Rows->Clear();
	dataGridView3->Columns->Clear();
	dataGridView3->Refresh();
	dataGridView3->ColumnCount = N + 3;
	dataGridView3->RowCount = M + 3;
	for (int i = 0; i < N + 1; i++) {
		dataGridView3->Rows[0]->Cells[i + 2]->Value = 2 * i * 1.0 / N;
		dataGridView3->Rows[1]->Cells[i + 2]->Value = i;
	}
	for (int j = 0; j < M + 1; j++) {
		dataGridView3->Rows[j + 2]->Cells[0]->Value = j * 1.0 / M;
		dataGridView3->Rows[j + 2]->Cells[1]->Value = j;
	}
	dataGridView3->Rows[0]->Cells[1]->Value = gcnew String("x");
	dataGridView3->Rows[1]->Cells[0]->Value = gcnew String("y");
	dataGridView3->Rows[1]->Cells[1]->Value = gcnew String("j/i");
	double max = 0;
	double x = 0;
	double y = 0;

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < M + 1; j++) {
			double z = abs(-v2[i][j] + v22[2*i][2*j]);
			dataGridView3->Rows[j + 2]->Cells[i + 2]->Value = z;
			if (z > max) {
				max = z;
				x = -1 * j * 1.0 / M;
				y = i * 1.0 / N;
			}
		}
	}

	const std::clock_t c_end = std::clock();
	const auto t_end = std::chrono::high_resolution_clock::now();
	label1->Text = "\n ���-�� ����� v2: " + System::Convert::ToString(index) +
		"\n ���-�� ����� v22: " + System::Convert::ToString(index2) +
		"\n ����������� �������� v2: " + System::Convert::ToString(Eps_max) +
		"\n ����������� �������� v22: " + System::Convert::ToString(Eps_max2) +
		"\n ����������� ������� v22-v2: " + System::Convert::ToString(max) +
		"\n �������� Tau: " + System::Convert::ToString(tau) +
		"\n �����: " + System::Convert::ToString((c_end - c_start) / CLOCKS_PER_SEC) + "s\n" +
		"\n ������� ���� �� ���. ����������� R(0) v2: " + System::Convert::ToString(MaxF) +
		"\n ������� ���� �� ���. ����������� R(0) v22: " + System::Convert::ToString(MaxF2) +
		"\n ������� ���� �� ������ R(p): v2 " + System::Convert::ToString(abs(temp2)) +
		"\n ������� ���� �� ������ R(p): v22 " + System::Convert::ToString(abs(temp22));
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dataGridView1_ColumnAdded(System::Object^ sender, System::Windows::Forms::DataGridViewColumnEventArgs^ e) {
	e->Column->FillWeight = 1;
}
private: System::Void dataGridView2_ColumnAdded(System::Object^ sender, System::Windows::Forms::DataGridViewColumnEventArgs^ e) {
	e->Column->FillWeight = 1;
}
private: System::Void dataGridView3_ColumnAdded(System::Object^ sender, System::Windows::Forms::DataGridViewColumnEventArgs^ e) {
	e->Column->FillWeight = 1;
}
};
}
