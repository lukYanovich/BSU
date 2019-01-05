namespace _2
{
    partial class Authrorization
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
            this.User = new System.Windows.Forms.Label();
            this.Password = new System.Windows.Forms.Label();
            this.OK = new System.Windows.Forms.Button();
            this.Exit = new System.Windows.Forms.Button();
            this.Create_user = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox_User = new System.Windows.Forms.TextBox();
            this.textBox_Password = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // User
            // 
            this.User.AutoSize = true;
            this.User.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.User.Location = new System.Drawing.Point(27, 13);
            this.User.Name = "User";
            this.User.Size = new System.Drawing.Size(42, 17);
            this.User.TabIndex = 0;
            this.User.Text = "User:";
            // 
            // Password
            // 
            this.Password.AutoSize = true;
            this.Password.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Password.Location = new System.Drawing.Point(12, 42);
            this.Password.Name = "Password";
            this.Password.Size = new System.Drawing.Size(73, 17);
            this.Password.TabIndex = 1;
            this.Password.Text = "Password:";
            // 
            // OK
            // 
            this.OK.Location = new System.Drawing.Point(12, 76);
            this.OK.Name = "OK";
            this.OK.Size = new System.Drawing.Size(93, 36);
            this.OK.TabIndex = 2;
            this.OK.Text = "OK";
            this.OK.UseVisualStyleBackColor = true;
            this.OK.Click += new System.EventHandler(this.OK_Click);
            // 
            // Exit
            // 
            this.Exit.Location = new System.Drawing.Point(123, 76);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(93, 36);
            this.Exit.TabIndex = 3;
            this.Exit.Text = "Exit";
            this.Exit.UseVisualStyleBackColor = true;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // Create_user
            // 
            this.Create_user.Location = new System.Drawing.Point(78, 154);
            this.Create_user.Name = "Create_user";
            this.Create_user.Size = new System.Drawing.Size(75, 23);
            this.Create_user.TabIndex = 4;
            this.Create_user.Text = "Create user";
            this.Create_user.UseVisualStyleBackColor = true;
            this.Create_user.Click += new System.EventHandler(this.Create_user_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(54, 124);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(127, 17);
            this.label3.TabIndex = 5;
            this.label3.Text = "Are you new here?";
            // 
            // textBox_User
            // 
            this.textBox_User.Location = new System.Drawing.Point(91, 15);
            this.textBox_User.Name = "textBox_User";
            this.textBox_User.Size = new System.Drawing.Size(125, 20);
            this.textBox_User.TabIndex = 6;
            // 
            // textBox_Password
            // 
            this.textBox_Password.Location = new System.Drawing.Point(91, 41);
            this.textBox_Password.Name = "textBox_Password";
            this.textBox_Password.Size = new System.Drawing.Size(125, 20);
            this.textBox_Password.TabIndex = 7;
            // 
            // Authrorization
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(234, 191);
            this.Controls.Add(this.textBox_Password);
            this.Controls.Add(this.textBox_User);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Create_user);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.OK);
            this.Controls.Add(this.Password);
            this.Controls.Add(this.User);
            this.Name = "Authrorization";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Authrorization";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label User;
        private System.Windows.Forms.Label Password;
        private System.Windows.Forms.Button OK;
        private System.Windows.Forms.Button Exit;
        private System.Windows.Forms.Button Create_user;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox_User;
        private System.Windows.Forms.TextBox textBox_Password;
    }
}