using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Globalization;
using System.IO;
using System.Text.Json;
using System.Windows.Forms;

namespace _04
{
    public partial class BD04 : Form
    {
        List<Entry> table;

        int dataId;
        string dataSpec, dataName, dataOw;
        float dataAge;

        Entry entry;

        string path, json, newjson;

        public class Entry
        {
            public int id { get; set; }
            public string species { get; set; }
            public string name { get; set; }
            public float age { get; set; }
            public string owner { get; set; }
        }
        public BD04()
        {
            InitializeComponent();
        }

        private void BD04_Load(object sender, EventArgs e) {
            path = "../../petz.json";
            json = File.ReadAllText(path);
            table = JsonSerializer.Deserialize<List<Entry>>(json);
            grid.DataSource = table;
        }

        private void add_Click(object sender, EventArgs e)
        {
            if (id.Text == "" || dataId < 0 || age.Text == "" || dataAge <= 0 || dataSpec == "" || dataName == "" || dataOw == "")
                MessageBox.Show("Поле # должно быть целым числом > 0" + 
                "\n" + "Поле Species не может быть пустым" +
                "\n" + "Поле Name не может быть пустым" +
                "\n" + "Поле Age должно быть числом > 0" +
                "\n" + "Поле Owner не может быть пустым", "Неверно заполненные данные");

            else
            {
                entry = new Entry()
                {
                    id = dataId,
                    species = dataSpec,
                    name = dataName,
                    age = dataAge,
                    owner = dataOw
                };

                table.Add(entry);

                newjson = JsonSerializer.Serialize(table);
                File.WriteAllText(path, newjson);

            }
        }

        private void id_TextChanged(object sender, EventArgs e)
        {
            int.TryParse(id.Text, out dataId);
        }

        private void upd_Click(object sender, EventArgs e)
        {
            grid.DataSource = "";
            grid.DataSource = table;
        }

        private void spec_TextChanged(object sender, EventArgs e)
        {
            dataSpec = spec.Text;
        }

        private void name_TextChanged(object sender, EventArgs e)
        {
            dataName = name.Text;
        }

        private void owner_TextChanged(object sender, EventArgs e)
        {
            dataOw = owner.Text;
        }

        private void age_TextChanged(object sender, EventArgs e)
        {
            float.TryParse(age.Text, NumberStyles.Any, CultureInfo.InvariantCulture, out dataAge);
        }


    }
}
