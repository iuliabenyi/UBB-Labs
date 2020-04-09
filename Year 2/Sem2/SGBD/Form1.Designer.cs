namespace SGBD_Lab1
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.dgvItems = new System.Windows.Forms.DataGridView();
			this.dgvLoot = new System.Windows.Forms.DataGridView();
			this.btnUpdateDB = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.tbID = new System.Windows.Forms.TextBox();
			this.tbLoot = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.tbBiom = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.tbPlayer = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.tbDurability = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.tbUsage = new System.Windows.Forms.TextBox();
			this.label7 = new System.Windows.Forms.Label();
			this.tbType = new System.Windows.Forms.TextBox();
			this.label8 = new System.Windows.Forms.Label();
			this.tbName = new System.Windows.Forms.TextBox();
			this.label9 = new System.Windows.Forms.Label();
			this.btnAdd = new System.Windows.Forms.Button();
			this.btnRemove = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.dgvItems)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dgvLoot)).BeginInit();
			this.SuspendLayout();
			// 
			// dgvItems
			// 
			this.dgvItems.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgvItems.Location = new System.Drawing.Point(55, 26);
			this.dgvItems.Name = "dgvItems";
			this.dgvItems.Size = new System.Drawing.Size(325, 185);
			this.dgvItems.TabIndex = 0;
			// 
			// dgvLoot
			// 
			this.dgvLoot.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dgvLoot.Location = new System.Drawing.Point(55, 241);
			this.dgvLoot.Name = "dgvLoot";
			this.dgvLoot.Size = new System.Drawing.Size(325, 185);
			this.dgvLoot.TabIndex = 1;
			// 
			// btnUpdateDB
			// 
			this.btnUpdateDB.Location = new System.Drawing.Point(561, 348);
			this.btnUpdateDB.Name = "btnUpdateDB";
			this.btnUpdateDB.Size = new System.Drawing.Size(136, 47);
			this.btnUpdateDB.TabIndex = 2;
			this.btnUpdateDB.Text = "Update DB";
			this.btnUpdateDB.UseVisualStyleBackColor = true;
			this.btnUpdateDB.Click += new System.EventHandler(this.btnUpdateDB_Click);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(460, 36);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(41, 13);
			this.label1.TabIndex = 3;
			this.label1.Text = "Item ID";
			// 
			// tbID
			// 
			this.tbID.Location = new System.Drawing.Point(523, 33);
			this.tbID.Name = "tbID";
			this.tbID.Size = new System.Drawing.Size(155, 20);
			this.tbID.TabIndex = 4;
			// 
			// tbLoot
			// 
			this.tbLoot.Location = new System.Drawing.Point(523, 215);
			this.tbLoot.Name = "tbLoot";
			this.tbLoot.Size = new System.Drawing.Size(155, 20);
			this.tbLoot.TabIndex = 8;
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(460, 218);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(42, 13);
			this.label3.TabIndex = 7;
			this.label3.Text = "Loot ID";
			// 
			// tbBiom
			// 
			this.tbBiom.Location = new System.Drawing.Point(523, 189);
			this.tbBiom.Name = "tbBiom";
			this.tbBiom.Size = new System.Drawing.Size(155, 20);
			this.tbBiom.TabIndex = 10;
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(460, 192);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(44, 13);
			this.label4.TabIndex = 9;
			this.label4.Text = "Biom ID";
			// 
			// tbPlayer
			// 
			this.tbPlayer.Location = new System.Drawing.Point(523, 163);
			this.tbPlayer.Name = "tbPlayer";
			this.tbPlayer.Size = new System.Drawing.Size(155, 20);
			this.tbPlayer.TabIndex = 12;
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(460, 166);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(50, 13);
			this.label5.TabIndex = 11;
			this.label5.Text = "Player ID";
			// 
			// tbDurability
			// 
			this.tbDurability.Location = new System.Drawing.Point(523, 137);
			this.tbDurability.Name = "tbDurability";
			this.tbDurability.Size = new System.Drawing.Size(155, 20);
			this.tbDurability.TabIndex = 14;
			// 
			// label6
			// 
			this.label6.AutoSize = true;
			this.label6.Location = new System.Drawing.Point(460, 140);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(50, 13);
			this.label6.TabIndex = 13;
			this.label6.Text = "Durability";
			// 
			// tbUsage
			// 
			this.tbUsage.Location = new System.Drawing.Point(523, 111);
			this.tbUsage.Name = "tbUsage";
			this.tbUsage.Size = new System.Drawing.Size(155, 20);
			this.tbUsage.TabIndex = 16;
			// 
			// label7
			// 
			this.label7.AutoSize = true;
			this.label7.Location = new System.Drawing.Point(460, 114);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(38, 13);
			this.label7.TabIndex = 15;
			this.label7.Text = "Usage";
			// 
			// tbType
			// 
			this.tbType.Location = new System.Drawing.Point(523, 85);
			this.tbType.Name = "tbType";
			this.tbType.Size = new System.Drawing.Size(155, 20);
			this.tbType.TabIndex = 18;
			// 
			// label8
			// 
			this.label8.AutoSize = true;
			this.label8.Location = new System.Drawing.Point(460, 88);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(31, 13);
			this.label8.TabIndex = 17;
			this.label8.Text = "Type";
			// 
			// tbName
			// 
			this.tbName.Location = new System.Drawing.Point(523, 59);
			this.tbName.Name = "tbName";
			this.tbName.Size = new System.Drawing.Size(155, 20);
			this.tbName.TabIndex = 20;
			// 
			// label9
			// 
			this.label9.AutoSize = true;
			this.label9.Location = new System.Drawing.Point(460, 62);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(35, 13);
			this.label9.TabIndex = 19;
			this.label9.Text = "Name";
			// 
			// btnAdd
			// 
			this.btnAdd.Location = new System.Drawing.Point(463, 280);
			this.btnAdd.Name = "btnAdd";
			this.btnAdd.Size = new System.Drawing.Size(136, 47);
			this.btnAdd.TabIndex = 21;
			this.btnAdd.Text = "Add";
			this.btnAdd.UseVisualStyleBackColor = true;
			this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
			// 
			// btnRemove
			// 
			this.btnRemove.Location = new System.Drawing.Point(652, 280);
			this.btnRemove.Name = "btnRemove";
			this.btnRemove.Size = new System.Drawing.Size(136, 47);
			this.btnRemove.TabIndex = 22;
			this.btnRemove.Text = "Remove";
			this.btnRemove.UseVisualStyleBackColor = true;
			this.btnRemove.Click += new System.EventHandler(this.btnRemove_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 490);
			this.Controls.Add(this.btnRemove);
			this.Controls.Add(this.btnAdd);
			this.Controls.Add(this.tbName);
			this.Controls.Add(this.label9);
			this.Controls.Add(this.tbType);
			this.Controls.Add(this.label8);
			this.Controls.Add(this.tbUsage);
			this.Controls.Add(this.label7);
			this.Controls.Add(this.tbDurability);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.tbPlayer);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.tbBiom);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.tbLoot);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.tbID);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.btnUpdateDB);
			this.Controls.Add(this.dgvLoot);
			this.Controls.Add(this.dgvItems);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Load += new System.EventHandler(this.Form1_Load);
			((System.ComponentModel.ISupportInitialize)(this.dgvItems)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dgvLoot)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.DataGridView dgvItems;
		private System.Windows.Forms.DataGridView dgvLoot;
		private System.Windows.Forms.Button btnUpdateDB;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox tbID;
		private System.Windows.Forms.TextBox tbLoot;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox tbBiom;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox tbPlayer;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox tbDurability;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.TextBox tbUsage;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.TextBox tbType;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.TextBox tbName;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.Button btnAdd;
		private System.Windows.Forms.Button btnRemove;
	}
}

