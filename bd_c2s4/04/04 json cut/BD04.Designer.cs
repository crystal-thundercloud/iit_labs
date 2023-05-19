namespace _04
{
    partial class BD04
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
            this.add = new System.Windows.Forms.Button();
            this.specLabel = new System.Windows.Forms.Label();
            this.ageLabel = new System.Windows.Forms.Label();
            this.idLabel = new System.Windows.Forms.Label();
            this.nameLabel = new System.Windows.Forms.Label();
            this.upd = new System.Windows.Forms.Button();
            this.id = new System.Windows.Forms.TextBox();
            this.spec = new System.Windows.Forms.TextBox();
            this.name = new System.Windows.Forms.TextBox();
            this.age = new System.Windows.Forms.TextBox();
            this.owner = new System.Windows.Forms.TextBox();
            this.owLabel = new System.Windows.Forms.Label();
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
            // add
            // 
            this.add.BackColor = System.Drawing.Color.MediumSeaGreen;
            this.add.Cursor = System.Windows.Forms.Cursors.Hand;
            this.add.FlatAppearance.BorderColor = System.Drawing.Color.DarkGreen;
            this.add.FlatAppearance.BorderSize = 5;
            this.add.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.add.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.add.Location = new System.Drawing.Point(12, 439);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(143, 43);
            this.add.TabIndex = 21;
            this.add.Text = "Добавить";
            this.add.UseVisualStyleBackColor = false;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // specLabel
            // 
            this.specLabel.AutoSize = true;
            this.specLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.specLabel.Location = new System.Drawing.Point(45, 394);
            this.specLabel.Name = "specLabel";
            this.specLabel.Size = new System.Drawing.Size(64, 16);
            this.specLabel.TabIndex = 8;
            this.specLabel.Text = "Species";
            // 
            // ageLabel
            // 
            this.ageLabel.AutoSize = true;
            this.ageLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ageLabel.Location = new System.Drawing.Point(357, 394);
            this.ageLabel.Name = "ageLabel";
            this.ageLabel.Size = new System.Drawing.Size(35, 16);
            this.ageLabel.TabIndex = 10;
            this.ageLabel.Text = "Age";
            // 
            // idLabel
            // 
            this.idLabel.AutoSize = true;
            this.idLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.idLabel.Location = new System.Drawing.Point(9, 394);
            this.idLabel.Name = "idLabel";
            this.idLabel.Size = new System.Drawing.Size(15, 16);
            this.idLabel.TabIndex = 11;
            this.idLabel.Text = "#";
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nameLabel.Location = new System.Drawing.Point(201, 394);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(48, 16);
            this.nameLabel.TabIndex = 13;
            this.nameLabel.Text = "Name";
            // 
            // upd
            // 
            this.upd.BackColor = System.Drawing.Color.SkyBlue;
            this.upd.Cursor = System.Windows.Forms.Cursors.Hand;
            this.upd.FlatAppearance.BorderColor = System.Drawing.Color.SteelBlue;
            this.upd.FlatAppearance.BorderSize = 5;
            this.upd.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.upd.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.upd.Location = new System.Drawing.Point(204, 439);
            this.upd.Name = "upd";
            this.upd.Size = new System.Drawing.Size(143, 43);
            this.upd.TabIndex = 22;
            this.upd.Text = "Обновить";
            this.upd.UseVisualStyleBackColor = false;
            this.upd.Click += new System.EventHandler(this.upd_Click);
            // 
            // id
            // 
            this.id.Location = new System.Drawing.Point(12, 413);
            this.id.Name = "id";
            this.id.Size = new System.Drawing.Size(30, 20);
            this.id.TabIndex = 16;
            this.id.TextChanged += new System.EventHandler(this.id_TextChanged);
            // 
            // spec
            // 
            this.spec.Location = new System.Drawing.Point(48, 413);
            this.spec.Name = "spec";
            this.spec.Size = new System.Drawing.Size(150, 20);
            this.spec.TabIndex = 17;
            this.spec.TextChanged += new System.EventHandler(this.spec_TextChanged);
            // 
            // name
            // 
            this.name.Location = new System.Drawing.Point(204, 413);
            this.name.Name = "name";
            this.name.Size = new System.Drawing.Size(150, 20);
            this.name.TabIndex = 18;
            this.name.TextChanged += new System.EventHandler(this.name_TextChanged);
            // 
            // age
            // 
            this.age.Location = new System.Drawing.Point(360, 413);
            this.age.Name = "age";
            this.age.Size = new System.Drawing.Size(30, 20);
            this.age.TabIndex = 19;
            this.age.TextChanged += new System.EventHandler(this.age_TextChanged);
            // 
            // owner
            // 
            this.owner.Location = new System.Drawing.Point(398, 413);
            this.owner.Name = "owner";
            this.owner.Size = new System.Drawing.Size(150, 20);
            this.owner.TabIndex = 20;
            this.owner.TextChanged += new System.EventHandler(this.owner_TextChanged);
            // 
            // owLabel
            // 
            this.owLabel.AutoSize = true;
            this.owLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.owLabel.Location = new System.Drawing.Point(395, 394);
            this.owLabel.Name = "owLabel";
            this.owLabel.Size = new System.Drawing.Size(50, 16);
            this.owLabel.TabIndex = 24;
            this.owLabel.Text = "Owner";
            // 
            // BD04
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(568, 493);
            this.Controls.Add(this.owner);
            this.Controls.Add(this.owLabel);
            this.Controls.Add(this.name);
            this.Controls.Add(this.age);
            this.Controls.Add(this.spec);
            this.Controls.Add(this.id);
            this.Controls.Add(this.upd);
            this.Controls.Add(this.nameLabel);
            this.Controls.Add(this.idLabel);
            this.Controls.Add(this.ageLabel);
            this.Controls.Add(this.specLabel);
            this.Controls.Add(this.add);
            this.Controls.Add(this.grid);
            this.Name = "BD04";
            this.Text = "БД ЛР04";
            this.Load += new System.EventHandler(this.BD04_Load);
            ((System.ComponentModel.ISupportInitialize)(this.grid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView grid;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.Label specLabel;
        private System.Windows.Forms.Label ageLabel;
        private System.Windows.Forms.Label idLabel;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.Button upd;
        private System.Windows.Forms.TextBox id;
        private System.Windows.Forms.TextBox spec;
        private System.Windows.Forms.TextBox name;
        private System.Windows.Forms.TextBox age;
        private System.Windows.Forms.TextBox owner;
        private System.Windows.Forms.Label owLabel;
    }
}

