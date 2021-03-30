using Microsoft.SqlServer.Server;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Text_Editor
{
    public partial class Texteditor : Form
    {
        private ToolStripContainer stripcontainer;
        private ToolStrip toptoolstrip, lefttoolstrip, bootomtoolstrip, righttoolstrip;
        private ToolStripButton New, Open, Save, Saveas, copy, cut, paste, bold, italic, underline;
        private ToolStripComboBox fontname, fontsize;
        private ToolStripLabel username;
        private MenuStrip mainmenu;
        private RichTextBox textediting;
        private string directory = Directory.GetCurrentDirectory();
        private ToolStripMenuItem fileitem, edititem, helpitem;
        public static string userType = Login.userType;


        public Texteditor()
        {
            InitializeComponent();
            createtoolstripcontainer();
            this.Closing += new CancelEventHandler(this.Form1_Closing);
        }

        private void Texteditor_Load(object sender, EventArgs e)
        {
            this.ControlBox = true;
            this.Text = "Text Editor";
            this.AutoSize = true;
            this.AutoSizeMode = AutoSizeMode.GrowOnly;
        }
        private void createtoolstripcontainer()
        {
            stripcontainer = new ToolStripContainer();
            stripcontainer.Dock = DockStyle.Fill;
            createtoolstrip();
            createmenustrip();
            createlefttoolstrip();
            createrichtextbox();
            createbutton();
            this.Controls.Add(stripcontainer);
        }

        private void createrichtextbox()
        {
            textediting = new RichTextBox();
            textediting.Font = new Font("Times New Roman", 8);
            textediting.Dock = DockStyle.Fill;
            textediting.KeyDown += new KeyEventHandler (textediting_KeyDown);
            stripcontainer.ContentPanel.Controls.Add(textediting);
        }

        private void createtoolstrip()
        {
            toptoolstrip = new ToolStrip();
            toptoolstrip.BackColor = Color.DarkSeaGreen;

            New = new ToolStripButton();
            New.Image = Bitmap.FromFile(directory + "/new.png");
            New.Text = "New File";
            New.DisplayStyle = ToolStripItemDisplayStyle.Image;
            New.TextImageRelation = TextImageRelation.TextAboveImage;
            New.Click += new EventHandler(New_click);

            Open = new ToolStripButton();
            Open.Image = Bitmap.FromFile(directory + "/open.jpg");
            Open.Text = "Open File";
            Open.DisplayStyle = ToolStripItemDisplayStyle.Image;
            Open.TextImageRelation = TextImageRelation.TextAboveImage;
            Open.Click += new EventHandler(open_click);

            Save = new ToolStripButton();
            Save.Text = "Save File";
            Save.DisplayStyle = ToolStripItemDisplayStyle.Image;
            Save.TextImageRelation = TextImageRelation.TextAboveImage;
            Save.Image = Bitmap.FromFile(directory + "/save.jpg");
            Save.Click += new EventHandler(save_click);

            Saveas = new ToolStripButton();
            Saveas.Image = Bitmap.FromFile(directory + "/saveas.png");
            Saveas.Text = "Save As File";
            Saveas.DisplayStyle = ToolStripItemDisplayStyle.Image;
            Saveas.TextImageRelation = TextImageRelation.TextAboveImage;
            Saveas.Click += new EventHandler(saveas_click);

            bold = new ToolStripButton();
            bold.Image = Bitmap.FromFile(directory + "/bold.png");
            bold.Text = "Bold";
            bold.DisplayStyle = ToolStripItemDisplayStyle.Image;
            bold.TextImageRelation = TextImageRelation.TextAboveImage;
            bold.Click += new EventHandler(bold_click);

            italic = new ToolStripButton();
            italic.Image = Bitmap.FromFile(directory + "/italic.png");
            italic.Text = "Italic";
            italic.DisplayStyle = ToolStripItemDisplayStyle.Image;
            italic.TextImageRelation = TextImageRelation.TextAboveImage;
            italic.Click += new EventHandler(italic_click);

            underline = new ToolStripButton();
            underline.Image = Bitmap.FromFile(directory + "/underline.png");
            underline.Text = "Underline";
            underline.DisplayStyle = ToolStripItemDisplayStyle.Image;
            underline.TextImageRelation = TextImageRelation.TextAboveImage;
            underline.Click += new EventHandler(underline_click);

            fontname = new ToolStripComboBox();
            fontname.BackColor = Color.AntiqueWhite;
            fontname.FlatStyle = FlatStyle.Standard;
            fontname.DropDownStyle = ComboBoxStyle.DropDownList; 
            fontname.ForeColor = Color.Black;
            fontname.Items.Insert(0,"Times New Roman");
            fontname.SelectedIndex = 0;
            fontname.Items.Add("Arial");
            fontname.Items.Add("Helvetica");
            fontname.Items.Add("Calibri");
            fontname.Items.Add("Time");
            fontname.Click += new EventHandler(font_click);

            fontsize = new ToolStripComboBox();
            fontsize.BackColor = Color.AntiqueWhite;
            fontsize.FlatStyle = FlatStyle.Standard;
            fontsize.DropDownStyle = ComboBoxStyle.DropDownList;
            fontsize.ForeColor = Color.Black;
            fontsize.Items.Insert(0, "8");
            fontsize.SelectedIndex = 0;
            fontsize.Items.Add("10");
            fontsize.Items.Add("12");
            fontsize.Items.Add("14");
            fontsize.Items.Add("16");
            fontsize.Items.Add("18");
            fontsize.Items.Add("20");
            fontsize.Click += new EventHandler(font_click);
            fontsize.Click += new EventHandler(size_click);

            username = new ToolStripLabel();
            username.Text = "Username:" + Login.username;

            toptoolstrip.Items.AddRange(new ToolStripItem[] { New, Open, Save, Saveas, bold, italic, underline, fontname, fontsize, username });
            stripcontainer.TopToolStripPanel.Controls.Add(toptoolstrip);

        }

        private void createmenustrip()
        {
            string[] file = new string[] { "New   Ctrl+N", "Open  Ctrl+O", "Save  Ctrl+S", "Save As", "Logout" };
            string[] edit = new string[] { "Cut Ctrl+X", "Copy  Ctrl+C", "Paste Ctrl+V" };
            string[] help = new string[] { "About" };
            string[] fileicon = new string[] { "new.png", "open.jpg", "save.jpg", "saveas.png", "logout.png" };
            string[] editicon = new string[] { "cut.png", "copy.png", "paste.png" };
            mainmenu = new MenuStrip();
            mainmenu.BackColor = Color.MediumAquamarine;
            mainmenu.ForeColor = Color.Blue;
            mainmenu.Font = new Font("Times New Roman", 10);
            fileitem = new ToolStripMenuItem("&File");
            fileitem.Click += new EventHandler(fileitem_click);
            for (int i = 0; i < file.Length; i++)
            {
                string name = fileicon[i];
                var iconimage = new Bitmap(directory + "/" + name);
                fileitem.DropDownItems.Add(file[i], iconimage, new EventHandler(fileitem_click));
                mainmenu.Items.Add(fileitem);
            }

            edititem = new ToolStripMenuItem("&Edit");
            for (int i = 0; i < edit.Length; i++)
            {
                string name = editicon[i];
                var iconimage = new Bitmap(directory + "/" + name);
                edititem.Click += new EventHandler(edititem_click);
                edititem.DropDownItems.Add(edit[i], iconimage, new EventHandler(edititem_click));
                mainmenu.Items.Add(edititem);
            }

            helpitem = new ToolStripMenuItem("&Help");
            helpitem.ShowShortcutKeys = true;
            mainmenu.Items.Add(helpitem);
           for(int i = 0; i < help.Length; i++)
            {
                helpitem.DropDownItems.Add(help[i],null,new EventHandler(help_click));
            }

            stripcontainer.TopToolStripPanel.Controls.Add(mainmenu);
        }

        private void Form1_Closing(object sender, CancelEventArgs e)
        {
            e.Cancel = true;
            int Count = Application.OpenForms.OfType<Texteditor>().Count();
            while (Count!=1)
            {
                e.Cancel = false;
                Count--;
            }
            if (Count == 1)
            {
                e.Cancel = false;
                Login login = new Login();
                this.Hide();
                login.Show();
            }
        }

        private void createlefttoolstrip()
        {
            lefttoolstrip = new ToolStrip();
            righttoolstrip = new ToolStrip();
            lefttoolstrip.BackColor = Color.Gray;

            cut = new ToolStripButton();
            cut.Image = Bitmap.FromFile(directory + "/cut.png");
            cut.Text = "Cut";
            cut.DisplayStyle = ToolStripItemDisplayStyle.Image;
            cut.Click += new EventHandler(cutclick);
            cut.TextImageRelation = TextImageRelation.TextAboveImage;

            copy = new ToolStripButton();
            copy.Image = Bitmap.FromFile(directory + "/copy.png");
            copy.Text = "Copy";
            copy.DisplayStyle = ToolStripItemDisplayStyle.Image;
            copy.Click += new EventHandler(copyclick);
            copy.TextImageRelation = TextImageRelation.TextAboveImage;

            paste = new ToolStripButton();
            paste.Image = Bitmap.FromFile(directory + "/paste.png");
            paste.Text = "Paste";
            paste.DisplayStyle = ToolStripItemDisplayStyle.Image;
            paste.TextImageRelation = TextImageRelation.TextAboveImage;
            paste.Click += new EventHandler(pasteclick);

            lefttoolstrip.Items.AddRange(new ToolStripItem[] { cut, copy, paste });
            stripcontainer.RightToolStripPanel.Controls.Add(righttoolstrip);
            stripcontainer.LeftToolStripPanel.Controls.Add(lefttoolstrip);
        }


        private void createbutton()
        {
            bootomtoolstrip = new ToolStrip();
            stripcontainer.BottomToolStripPanel.Controls.Add(bootomtoolstrip);
        }

        private void fileitem_click(object sender, EventArgs e)
        {
            var item = sender as ToolStripMenuItem;
            var itemText = item.Text;
            if (userType.Equals("Edit"))
            {

                switch (itemText)
                {
                    case "New   Ctrl+N":
                        Texteditor form = new Texteditor();
                        form.Show();
                        break;
                    case "Open  Ctrl+O":
                        OpenFileDialog openFile = new OpenFileDialog();
                        openFile.DefaultExt = "*.rtf";
                        openFile.Filter = "RTF Files|*.rtf";
                        if (openFile.ShowDialog() == DialogResult.OK)
                        {
                            textediting.LoadFile(openFile.FileName);
                            filePath = openFile.FileName;
                        }
                        break;
                    case "Save  Ctrl+S":
                        if (File.Exists(filePath))
                        {
                            byte[] buffer = Encoding.ASCII.GetBytes(textediting.Text);
                            MemoryStream ms = new MemoryStream(buffer);
                            FileStream file = new FileStream(filePath, FileMode.Create, FileAccess.Write);
                            ms.WriteTo(file);
                            file.Close();
                            ms.Close();
                        }
                        else
                        {
                            SaveFileDialog savefile = new SaveFileDialog();
                            savefile.Filter = "Rich Text File | *.rtf";
                            savefile.OverwritePrompt = false;
                            if (savefile.ShowDialog() == DialogResult.OK)
                            {
                                textediting.SaveFile(savefile.FileName);
                                filePath = savefile.FileName;
                            }
                        }
                        break;
                    case "Save As":
                        SaveFileDialog saveasfile = new SaveFileDialog();
                        saveasfile.DefaultExt = "*.rtf";
                        saveasfile.Filter = "RTF Files|*.rtf";
                        if (saveasfile.ShowDialog() == DialogResult.OK && saveasfile.FileName.Length > 0)
                        {
                            textediting.SaveFile(saveasfile.FileName);
                            filePath = saveasfile.FileName;
                        }
                        break;
                    case "Logout":
                        Login login = new Login();
                        for (int i = Application.OpenForms.Count - 1; i >= 0; i--)
                        {
                            var from = Application.OpenForms[i];
                            if (from.GetType() != typeof(Login))
                            {
                               from.Hide();
                            } 
                        }
                        login.Show();
                        break;

                    default:
                        break;
                }
            }

            else
            {

                switch (itemText)
                {
                    case "Logout":
                        Login login = new Login();
                        for (int i = Application.OpenForms.Count - 1; i >= 0; i--)
                        {
                            var from = Application.OpenForms[i];
                            if (from.GetType() != typeof(Login))
                            {
                                from.Hide();
                            }
                        }
                        login.Show();
                        break;
                    case "Open":
                        OpenFileDialog openFile = new OpenFileDialog();
                        openFile.DefaultExt = "*.rtf";
                        openFile.Filter = "RTF Files|*.rtf";
                        if (openFile.ShowDialog() == System.Windows.Forms.DialogResult.OK && openFile.FileName.Length > 0)
                        {
                            textediting.LoadFile(openFile.FileName);
                        }
                        break;

                    default:
                        break;
                }
                
            }
        }

        private void edititem_click(object sender, EventArgs e)
        {
            var item = sender as ToolStripMenuItem;
            var itemText = item.Text;

            if (userType.Equals("Edit"))
            {

                switch (itemText)
                {
                    case "Copy  Ctrl+C":
                        textediting.Copy();
                        break;
                    case "Cut Ctrl+X":
                        textediting.Cut();
                        break;
                    case "Paste Ctrl+V":
                        textediting.Paste();
                        break;
                    default:
                        break;
                }
            }
        }

        private void help_click(object sender, EventArgs e)
        {
            var item = sender as ToolStripMenuItem;
            var itemtext = item.Text;
            if (itemtext.Equals("About"))
            {
                MessageBox.Show("Welcome!!!");
            }
        }

        private void New_click(object sender, EventArgs e)
        {
            if (userType.Equals("Edit"))
            {
                Texteditor form = new Texteditor();
                form.ControlBox = true;
                form.Show();
            }
        }

        private void open_click(object sender, EventArgs e)
        {

            OpenFileDialog openFile = new OpenFileDialog();
            openFile.DefaultExt = "*.rtf";
            openFile.Filter = "RTF Files|*.rtf";
            openFile.CheckFileExists = true;
            openFile.CheckPathExists = true;
            if (openFile.ShowDialog() ==DialogResult.OK)
            {
                textediting.LoadFile(openFile.FileName);
                filePath = openFile.FileName;
            }
        }

        private string filePath = string.Empty;
        private void save_click(object sender, EventArgs e)
        {
            if (userType.Equals("Edit"))
            {
                if (File.Exists(filePath))
                {
                    byte[] buffer = Encoding.ASCII.GetBytes(textediting.Text);
                    MemoryStream ms = new MemoryStream(buffer);
                    FileStream file = new FileStream(filePath, FileMode.Create, FileAccess.Write);
                    ms.WriteTo(file);
                    file.Close();
                    ms.Close();
                }
                else
                {
                    SaveFileDialog savefile = new SaveFileDialog();
                    savefile.Filter = "Rich Text File | *.rtf";
                    savefile.OverwritePrompt = false;
                    if (savefile.ShowDialog() == DialogResult.OK)
                    {
                        textediting.SaveFile(savefile.FileName);
                        filePath = savefile.FileName;
                    }
                }
            }
        }

        private void saveas_click(object sender, EventArgs e)
        {
            MemoryStream userInput = new MemoryStream();
            if (userType.Equals("Edit"))
            {
                SaveFileDialog savefile = new SaveFileDialog();
                savefile.CreatePrompt = true;
                savefile.OverwritePrompt = true;
                savefile.DefaultExt = "*.rtf";
                savefile.Filter = "RTF Files|*.rtf";
                if (savefile.ShowDialog() == DialogResult.OK)
                {
                    textediting.SaveFile(savefile.FileName);
                    filePath = savefile.FileName;
                }
            }
        }

        private void bold_click(object sender, EventArgs e)
        {

            if (userType.Equals("Edit"))
            {
                if (textediting.SelectionLength > 0)
                {
                    textediting.SelectionFont = new Font(textediting.Font, FontStyle.Bold);
                }
            }
        }


        private void italic_click(object sender, EventArgs e)
        {
            if (userType.Equals("Edit"))
            {
                if (textediting.SelectionLength > 0)
                {

                    textediting.SelectionFont = new Font(textediting.Font, FontStyle.Italic);
                }
            }
        }

        private void underline_click(object sender, EventArgs e)
        {
            if (userType.Equals("Edit"))
            {

                if (textediting.SelectionLength > 0)
                {

                    textediting.SelectionFont = new Font(textediting.Font, FontStyle.Underline);
                }

            }
        }

        private void font_click(object sender, EventArgs e)
        {
            var item = sender as ToolStripComboBox;
            var itemText = item.Text;

            if (userType.Equals("Edit"))
            {
                switch (itemText)
                {
                    case "Times New Roman":
                        textediting.Font = new Font("Times New Roman", textediting.Font.Size);
                        break;
                    case "Arial":
                        textediting.Font = new Font("Arial", textediting.Font.Size);
                        break;
                    case "Calibri":
                        textediting.Font = new Font("Calibri", textediting.Font.Size);
                        break;
                    case "Halvetica":
                        textediting.Font = new Font("Halvetica", textediting.Font.Size);
                        break;
                    case "Time":
                        textediting.Font = new Font("Time", textediting.Font.Size);
                        break;
                    default:
                        break;
                }

            }
        }

        private void size_click(object sender, EventArgs e)
        {
            var item = sender as ToolStripComboBox;
            var itemText = item.Text;
            if (userType.Equals("Edit"))
            {

                switch (itemText)
                {
                    case "8":
                        textediting.Font = new Font(textediting.Font.Name, 8);
                        break;
                    case "10":
                        textediting.Font = new Font(textediting.Font.Name,  10);
                        break;
                    case "12":
                        textediting.Font = new Font(textediting.Font.Name, 12);
                        break;
                    case "14":
                        textediting.Font = new Font(textediting.Font.Name, 14);
                        break;
                    case "16":
                        textediting.Font = new Font(textediting.Font.Name, 16);
                        break;
                    case "18":
                        textediting.Font = new Font(textediting.Font.Name, 18);
                        break;
                    case "20":
                        textediting.Font = new Font(textediting.Font.Name, 20);
                        break;
                    default:
                        break;

                }
            }
        }
        private void copyclick(object sender,EventArgs e)
        {
            if (userType.Equals("Edit"))
            {
                textediting.Copy();
                   
            }
        }

        private void cutclick(object sender, EventArgs e)
        {
            if (userType.Equals("Edit"))
            {
                textediting.Cut();
            }
        }

        private void pasteclick(object sender, EventArgs e)
        {
            if (userType.Equals("Edit"))
            {
                textediting.Paste();
            }
        }
        int TexteditorCount = Application.OpenForms.OfType<Texteditor>().Count();
        private void textediting_KeyDown(object sender, KeyEventArgs e)
        {
            if (userType.Equals("Edit")) {
                if (e.Control && e.KeyCode == Keys.S)
                {
                    if (File.Exists(filePath))
                    {
                        byte[] buffer = Encoding.ASCII.GetBytes(textediting.Text);
                        MemoryStream ms = new MemoryStream(buffer);
                        FileStream file = new FileStream(filePath, FileMode.Create, FileAccess.Write);
                        ms.WriteTo(file);
                        file.Close();
                        ms.Close();
                    }
                    else
                    {
                        SaveFileDialog savefile = new SaveFileDialog();
                        savefile.Filter = "Rich Text File | *.rtf";
                        savefile.OverwritePrompt = false;
                        if (savefile.ShowDialog() == DialogResult.OK)
                        {
                            textediting.SaveFile(savefile.FileName);
                            filePath = savefile.FileName;
                        }
                    }
                    e.SuppressKeyPress = true;
                }
                if (e.Control && e.KeyCode == Keys.O)
                {
                    OpenFileDialog openfile = new OpenFileDialog();
                    openfile.Filter = "Rich Text File | *.rtf";
                    if (openfile.ShowDialog() == DialogResult.OK)
                    {
                        textediting.LoadFile(openfile.FileName);
                        filePath = openfile.FileName;
                    }
                    e.SuppressKeyPress = true;
                }
                if (e.Control && e.KeyCode == Keys.N)
                {
                    Texteditor form = new Texteditor();
                    form.Show();
                    e.SuppressKeyPress = true;
                }
            }
        }
    }
}
