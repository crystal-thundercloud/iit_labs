using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace _03
{
    public partial class BD03 : Form
    {
        string command, columns, table, cond;

        SqlConnection conn;
        SqlCommand cmd;
        SqlDataAdapter sda;
        DataTable dt;

        public BD03()
        {
            InitializeComponent();
        }

        private void BD03_Load(object sender, EventArgs e)
        {
            conn = new SqlConnection("Server=ASNO;Database=ShemarevaAM;User Id=ASNO\\cdctt;Password=root;Trusted_Connection=True;");
            // Server=myServerAddress;Database=myDataBase;User Id=myUsername;Password=myPassword;Trusted_Connection=True;

            try
            {
                conn.Open();
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message, "Ошибка подключения");
            }

            cols.SetSelected(0, true);

            reapplyStrings();
            completeQuery();
        }

        private void condit_TextChanged(object sender, EventArgs e)
        {
            completeQuery();
        }

        private void cols_SelectedIndexChanged(object sender, EventArgs e)
        {

            columns = "";
            int numcols = cols.SelectedItems.Count;

            for (int i = 0; i < numcols; i++)
            {
                columns += cols.SelectedItems[i];
                if (i < numcols - 1) columns += ", ";
            }

            reapplyStrings();

            completeQuery();
        }

        private void exec_Click(object sender, EventArgs e)
        {
            if (comText.Text.ToUpper().IndexOf("DROP") < 0 && comText.Text.ToUpper().IndexOf("TRUNCATE") < 0)
            {
                cmd = new SqlCommand(comText.Text, conn);

                dt = new DataTable();

                // если команда не select, то выполнить select сразу после неё
                if (comText.Text.IndexOf("SELECT") < 0)
                {
                    try
                    {
                        cmd.ExecuteNonQuery();
                    }
                    catch (SqlException ex)
                    {
                        MessageBox.Show(ex.Message, "Ошибка выполнения запроса");
                    }
                    cmd.CommandText = "SELECT * FROM " + table;
                }

                sda = new SqlDataAdapter(cmd);

                try
                {
                    sda.Fill(dt);
                    grid.DataSource = dt;
                }
                catch (SqlException ex)
                {
                    MessageBox.Show(ex.Message, "Ошибка выполнения запроса");
                }
            }
            // невозможность вставить картинку в messagebox - не преграда
            else MessageBox.Show("　　　　 .,,..;~`''''　　　　`''''＜``彡　} \r\n　 _...:=,`'　　 　︵　 т　︵　　X彡-J \r\n＜`　彡 /　　ミ　　,_人_.　＊彡　`~ \r\n　 `~=::　　　 　　　　　　 　　　Y \r\n　　 　i.　　　　　　　　　　　　 .: \r\n　　　.\\　　　　　　　,｡---.,,　　./ \r\n　　　　ヽ　／ﾞ''```\\;.{　　　 ＼／ \r\n　　　　　Y　　　`J..r_.彳　 　| \r\n　　　　　{　　　``　　`　　　i \r\n　　　　　\\　　　　　　　　　＼　　　..︵︵. \r\n　　　　　`＼　　　　　　　　　``ゞ.,/` oQ o`) \r\n　　　　　　`i,　　　　　　　　　　Y　 ω　/ \r\n　　　　 　　`i,　　　 　　.　　　　\"　　　/ \r\n　　　　　　`iミ　　　　　　　　　　　,,ノ \r\n　　　　 　 ︵Y..︵.,,　　　　　,,+..__ノ`` \r\n　　　　　(,`, З о　　　　,.ノ川彡ゞ彡　　＊ \r\n　　　　　 ゞ_,,,....彡彡~　　　`+Х彡彡彡彡*" + "\n\nКотик просит вас не дропать таблицы", "Убедительная просьба");

        }

        private void tab_SelectedItemChanged(object sender, EventArgs e)
        {
            reapplyStrings();
            columns = "";
            cols.Items.Clear();

            if (table == " fruitz ")
            {
                cols.Items.AddRange(new object[] {
                "*",
                "id",
                "fruit",
                "amount"});
            }

            else if (table == " dessertz ")
            {
                cols.Items.AddRange(new object[] {
                "*",
                "id",
                "dessert",
                "flavour",
                "amount"});
            }

            else if (table == " saucez ")
            {
                cols.Items.AddRange(new object[] {
                "*",
                "id",
                "sauce",
                "amount"});
            }

            else if (table == " orderz ")
            {
                cols.Items.AddRange(new object[] {
                "*",
                "id",
                "fruit",
                "dessert",
                "sauce",
                "cost"});
            }
            else cols.Items.AddRange(new object[] { "*" });

            cols.SetSelected(0, true);

            reapplyStrings();
            completeQuery();
        }

        private void BD03_FormClosed(object sender, FormClosedEventArgs e)
        {
            conn.Close();
        }

        private void manualQuery_CheckedChanged(object sender, EventArgs e)
        {
            completeQuery();
        }

        private void com_SelectedItemChanged(object sender, EventArgs e)
        {
            reapplyStrings();
            completeQuery();
        }

        private void completeQuery()
        {
            cond = condit.Text;

            if (manualQuery.Checked) comText.Text = condit.Text;

            else if (command.IndexOf("SELECT" ) >= 0)
            {
                condit.Text = cond;
                comText.Text = command + columns + " FROM " + table + cond;
            }

            else if (command.IndexOf("DELETE FROM") >= 0)
            {
                if (cond.IndexOf("WHERE") < 0) cond = cond.Insert(0, "WHERE ");
                condit.Text = cond;
                comText.Text = command + table + cond;
            }

            else if (command.IndexOf("INSERT INTO") >= 0)
            {
                if (cond.IndexOf("VALUES") < 0) cond = cond.Insert(0, "VALUES ");
                condit.Text = cond;
                if (columns != "") comText.Text = command + table + "(" + columns + ") " + cond;
                else comText.Text = command + table + columns + cond;
            }

            else if (command.IndexOf("UPDATE") >= 0)
            {
                if (cond.IndexOf("SET") < 0) cond = cond.Insert(0, "SET ");
                condit.Text = cond;
                comText.Text = command + table + cond;
            }

            else comText.Text = command + table + cond;
        }

        private void reapplyStrings()
        {
            command = com.Text;
            table = tab.Text;
            cond = condit.Text;
        }
    }
}
