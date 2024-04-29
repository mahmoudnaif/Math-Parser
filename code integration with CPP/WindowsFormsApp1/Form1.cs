using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        [DllImport("yaa.dll")]
        public static extern IntPtr Create(int y);

        [DllImport("yaa.dll")]
        public static extern void AddString(IntPtr ptr, char y);

        [DllImport("yaa.dll")]
        public static extern double returndouble(IntPtr ptr);
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {  
           

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            IntPtr ptr = Create(5);
            for(int i = 0; i < textBox1.Text.Length; i++) {
                AddString(ptr, textBox1.Text[i]);
            }


            double output = returndouble(ptr);
            string outputStr = output.ToString();
            MessageBox.Show(outputStr);
        }
    }
}
