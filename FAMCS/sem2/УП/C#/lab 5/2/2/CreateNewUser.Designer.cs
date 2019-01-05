namespace _2
{
    partial class CreateNewUser
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
            this.Username = new System.Windows.Forms.Label();
            this.Password = new System.Windows.Forms.Label();
            this.ConfimPassword = new System.Windows.Forms.Label();
            this.Create = new System.Windows.Forms.Button();
            this.Cancel = new System.Windows.Forms.Button();
            this.textBox_Username = new System.Windows.Forms.TextBox();
            this.textBox_Password = new System.Windows.Forms.TextBox();
            this.textBox_ConfimPassword = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Username
            // 
            this.Username.AutoSize = true;
            this.Username.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Username.Location = new System.Drawing.Point(23, 14);
            this.Username.Name = "Username";
            this.Username.Size = new System.Drawing.Size(68, 15);
            this.Username.TabIndex = 0;
            this.Username.Text = "Username:";
            // 
            // Password
            // 
            this.Password.AutoSize = true;
            this.Password.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Password.Location = new System.Drawing.Point(27, 49);
            this.Password.Name = "Password";
            this.Password.Size = new System.Drawing.Size(64, 15);
            this.Password.TabIndex = 1;
            this.Password.Text = "Password:";
            // 
            // ConfimPassword
            // 
            this.ConfimPassword.AutoSize = true;
            this.ConfimPassword.Location = new System.Drawing.Point(12, 87);
            this.ConfimPassword.Name = "ConfimPassword";
            this.ConfimPassword.Size = new System.Drawing.Size(91, 13);
            this.ConfimPassword.TabIndex = 2;
            this.ConfimPassword.Text = "Confim Password:";
            // 
            // Create
            // 
            this.Create.Location = new System.Drawing.Point(25, 118);
            this.Create.Name = "Create";
            this.Create.Size = new System.Drawing.Size(75, 34);
            this.Create.TabIndex = 3;
            this.Create.Text = "Create";
            this.Create.UseVisualStyleBackColor = true;
            this.Create.Click += new System.EventHandler(this.Create_Click);
            // 
            // Cancel
            // 
            this.Cancel.Location = new System.Drawing.Point(129, 118);
            this.Cancel.Name = "Cancel";
            this.Cancel.Size = new System.Drawing.Size(75, 34);
            this.Cancel.TabIndex = 4;
            this.Cancel.Text = "Cancel";
            this.Cancel.UseVisualStyleBackColor = true;
            this.Cancel.Click += new System.EventHandler(this.Cancel_Click);
            // 
            // textBox_Username
            // 
            this.textBox_Username.Location = new System.Drawing.Point(116, 12);
            this.textBox_Username.Name = "textBox_Username";
            this.textBox_Username.Size = new System.Drawing.Size(116, 20);
            this.textBox_Username.TabIndex = 5;
            // 
            // textBox_Password
            // 
            this.textBox_Password.Location = new System.Drawing.Point(116, 46);
            this.textBox_Password.Name = "textBox_Password";
            this.textBox_Password.Size = new System.Drawing.Size(116, 20);
            this.textBox_Password.TabIndex = 6;
            // 
            // textBox_ConfimPassword
            // 
            this.textBox_ConfimPassword.Location = new System.Drawing.Point(116, 84);
            this.textBox_ConfimPassword.Name = "textBox_ConfimPassword";
            this.textBox_ConfimPassword.Size = new System.Drawing.Size(116, 20);
            this.textBox_ConfimPassword.TabIndex = 7;
            // 
            // CreateNewUser
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(244, 161);
            this.Controls.Add(this.textBox_ConfimPassword);
            this.Controls.Add(this.textBox_Password);
            this.Controls.Add(this.textBox_Username);
            this.Controls.Add(this.Cancel);
            this.Controls.Add(this.Create);
            this.Controls.Add(this.ConfimPassword);
            this.Controls.Add(this.Password);
            this.Controls.Add(this.Username);
            this.Name = "CreateNewUser";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CreateNewUser";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Username;
        private System.Windows.Forms.Label Password;
        private System.Windows.Forms.Label ConfimPassword;
        private System.Windows.Forms.Button Create;
        private System.Windows.Forms.Button Cancel;
        private System.Windows.Forms.TextBox textBox_Username;
        private System.Windows.Forms.TextBox textBox_Password;
        private System.Windows.Forms.TextBox textBox_ConfimPassword;
    }
}