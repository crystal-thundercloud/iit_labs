namespace _03
{
    partial class BD03
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.grid = new System.Windows.Forms.DataGridView();
            this.exec = new System.Windows.Forms.Button();
            this.com = new System.Windows.Forms.DomainUpDown();
            this.comText = new System.Windows.Forms.Label();
            this.tab = new System.Windows.Forms.DomainUpDown();
            this.colsLabel = new System.Windows.Forms.Label();
            this.cols = new System.Windows.Forms.ListBox();
            this.tabLabel = new System.Windows.Forms.Label();
            this.comLabel = new System.Windows.Forms.Label();
            this.condit = new System.Windows.Forms.TextBox();
            this.condLabel = new System.Windows.Forms.Label();
            this.hintQuotes = new System.Windows.Forms.Label();
            this.manualQuery = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.grid)).BeginInit();
            this.SuspendLayout();
            // 
            // grid
            // 
            this.grid.AllowUserToAddRows = false;
            this.grid.AllowUserToDeleteRows = false;
            this.grid.AllowUserToOrderColumns = true;
            this.grid.BackgroundColor = System.Drawing.Color.Honeydew;
            this.grid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.grid.GridColor = System.Drawing.Color.DarkGreen;
            this.grid.Location = new System.Drawing.Point(12, 12);
            this.grid.Name = "grid";
            this.grid.ReadOnly = true;
            this.grid.Size = new System.Drawing.Size(548, 371);
            this.grid.TabIndex = 0;
            // 
            // exec
            // 
            this.exec.BackColor = System.Drawing.Color.MediumSeaGreen;
            this.exec.Cursor = System.Windows.Forms.Cursors.Hand;
            this.exec.FlatAppearance.BorderColor = System.Drawing.Color.SeaGreen;
            this.exec.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.exec.Location = new System.Drawing.Point(417, 410);
            this.exec.Name = "exec";
            this.exec.Size = new System.Drawing.Size(143, 43);
            this.exec.TabIndex = 1;
            this.exec.Text = "Выполнить";
            this.exec.UseVisualStyleBackColor = false;
            this.exec.Click += new System.EventHandler(this.exec_Click);
            // 
            // com
            // 
            this.com.Items.Add("SELECT ");
            this.com.Items.Add("INSERT INTO ");
            this.com.Items.Add("UPDATE ");
            this.com.Items.Add("DELETE FROM ");
            this.com.Location = new System.Drawing.Point(12, 410);
            this.com.Name = "com";
            this.com.Size = new System.Drawing.Size(106, 20);
            this.com.TabIndex = 4;
            this.com.Text = "SELECT ";
            this.com.SelectedItemChanged += new System.EventHandler(this.com_SelectedItemChanged);
            // 
            // comText
            // 
            this.comText.AutoSize = true;
            this.comText.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comText.Location = new System.Drawing.Point(12, 502);
            this.comText.MaximumSize = new System.Drawing.Size(551, 1000);
            this.comText.Name = "comText";
            this.comText.Size = new System.Drawing.Size(420, 32);
            this.comText.TabIndex = 5;
            this.comText.Text = "Здесь будет выводиться текст получившейся команды.\r\nПоможет перепроверить данные " +
    "перед выполнением запроса.\r\n";
            // 
            // tab
            // 
            this.tab.Items.Add(" fruitz ");
            this.tab.Items.Add(" dessertz ");
            this.tab.Items.Add(" saucez ");
            this.tab.Items.Add(" orderz ");
            this.tab.Location = new System.Drawing.Point(12, 472);
            this.tab.Name = "tab";
            this.tab.Size = new System.Drawing.Size(106, 20);
            this.tab.TabIndex = 6;
            this.tab.Text = " fruitz ";
            this.tab.SelectedItemChanged += new System.EventHandler(this.tab_SelectedItemChanged);
            // 
            // colsLabel
            // 
            this.colsLabel.AutoSize = true;
            this.colsLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.colsLabel.Location = new System.Drawing.Point(131, 394);
            this.colsLabel.Name = "colsLabel";
            this.colsLabel.Size = new System.Drawing.Size(71, 16);
            this.colsLabel.TabIndex = 8;
            this.colsLabel.Text = "Столбцы";
            // 
            // cols
            // 
            this.cols.FormattingEnabled = true;
            this.cols.Items.AddRange(new object[] {
            "*",
            "id",
            "fruit",
            "amount"});
            this.cols.Location = new System.Drawing.Point(134, 410);
            this.cols.Name = "cols";
            this.cols.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.cols.Size = new System.Drawing.Size(78, 82);
            this.cols.TabIndex = 9;
            this.cols.SelectedIndexChanged += new System.EventHandler(this.cols_SelectedIndexChanged);
            // 
            // tabLabel
            // 
            this.tabLabel.AutoSize = true;
            this.tabLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tabLabel.Location = new System.Drawing.Point(9, 456);
            this.tabLabel.Name = "tabLabel";
            this.tabLabel.Size = new System.Drawing.Size(71, 16);
            this.tabLabel.TabIndex = 10;
            this.tabLabel.Text = "Таблица";
            // 
            // comLabel
            // 
            this.comLabel.AutoSize = true;
            this.comLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comLabel.Location = new System.Drawing.Point(9, 394);
            this.comLabel.Name = "comLabel";
            this.comLabel.Size = new System.Drawing.Size(71, 16);
            this.comLabel.TabIndex = 11;
            this.comLabel.Text = "Команда";
            // 
            // condit
            // 
            this.condit.Location = new System.Drawing.Point(228, 409);
            this.condit.Multiline = true;
            this.condit.Name = "condit";
            this.condit.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.condit.Size = new System.Drawing.Size(172, 63);
            this.condit.TabIndex = 12;
            this.condit.TextChanged += new System.EventHandler(this.condit_TextChanged);
            // 
            // condLabel
            // 
            this.condLabel.AutoSize = true;
            this.condLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.condLabel.Location = new System.Drawing.Point(225, 393);
            this.condLabel.Name = "condLabel";
            this.condLabel.Size = new System.Drawing.Size(205, 16);
            this.condLabel.TabIndex = 13;
            this.condLabel.Text = "Условия / Данные / Запрос";
            // 
            // hintQuotes
            // 
            this.hintQuotes.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.hintQuotes.Location = new System.Drawing.Point(420, 462);
            this.hintQuotes.Name = "hintQuotes";
            this.hintQuotes.Size = new System.Drawing.Size(143, 30);
            this.hintQuotes.TabIndex = 14;
            this.hintQuotes.Text = "Вместо \"кавычек\" используйте \'апострофы\'";
            // 
            // manualQuery
            // 
            this.manualQuery.AutoSize = true;
            this.manualQuery.Location = new System.Drawing.Point(228, 475);
            this.manualQuery.Name = "manualQuery";
            this.manualQuery.Size = new System.Drawing.Size(158, 17);
            this.manualQuery.TabIndex = 15;
            this.manualQuery.Text = "Написать запрос вручную";
            this.manualQuery.UseVisualStyleBackColor = true;
            this.manualQuery.CheckedChanged += new System.EventHandler(this.manualQuery_CheckedChanged);
            // 
            // BD03
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(568, 552);
            this.Controls.Add(this.manualQuery);
            this.Controls.Add(this.hintQuotes);
            this.Controls.Add(this.condLabel);
            this.Controls.Add(this.condit);
            this.Controls.Add(this.comLabel);
            this.Controls.Add(this.tabLabel);
            this.Controls.Add(this.cols);
            this.Controls.Add(this.colsLabel);
            this.Controls.Add(this.tab);
            this.Controls.Add(this.comText);
            this.Controls.Add(this.com);
            this.Controls.Add(this.exec);
            this.Controls.Add(this.grid);
            this.Name = "BD03";
            this.Text = "БД ЛР03";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.BD03_FormClosed);
            this.Load += new System.EventHandler(this.BD03_Load);
            ((System.ComponentModel.ISupportInitialize)(this.grid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView grid;
        private System.Windows.Forms.Button exec;
        private System.Windows.Forms.DomainUpDown com;
        private System.Windows.Forms.Label comText;
        private System.Windows.Forms.DomainUpDown tab;
        private System.Windows.Forms.Label colsLabel;
        private System.Windows.Forms.ListBox cols;
        private System.Windows.Forms.Label tabLabel;
        private System.Windows.Forms.Label comLabel;
        private System.Windows.Forms.TextBox condit;
        private System.Windows.Forms.Label condLabel;
        private System.Windows.Forms.Label hintQuotes;
        private System.Windows.Forms.CheckBox manualQuery;
    }
}

