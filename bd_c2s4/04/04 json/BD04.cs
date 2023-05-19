using System;
using System.ComponentModel;
using System.Globalization;
using System.IO;
using System.Text.Json;
using System.Windows.Forms;

namespace _04
{
    public partial class BD04 : Form
    {
        BindingList<Entry> table; //binding list сразу обновляет данные

        int dataId;
        string dataSpec, dataName, dataOw;
        float dataAge;

        Entry entry;

        string path, json, newjson;

        public class Entry
        {
            public int No { get; set; }
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
            table = JsonSerializer.Deserialize<BindingList<Entry>>(json);
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
                    No = dataId,
                    species = dataSpec,
                    name = dataName,
                    age = dataAge,
                    owner = dataOw
                };

                table.Add(entry);

                //grid.DataSource = ""; //если бы не binding list
                //grid.DataSource = table; //пришлось бы каждый раз перепривязывать datasource


                newjson = JsonSerializer.Serialize(table);
                File.WriteAllText(path, newjson);

            }
        }

        private void del_Click(object sender, EventArgs e)
        {
            if (id.Text == "" || dataId < 0) MessageBox.Show("Поле id должно быть целым числом > 0", "Неверно заполненные данные");
            else
            {
                bool found = false;
                for (int i = 0; i < table.Count; i++)
                {
                    Entry en = table[i];
                    if (en.No == dataId)
                    {
                        table.Remove(en);
                        newjson = JsonSerializer.Serialize(table);
                        File.WriteAllText(path, newjson);
                        break;
                    }
                }
                if (!found) MessageBox.Show("Данные с номером " + dataId + " не найдены", "Данные не найдены");
            }
        }

        private void upd_Click(object sender, EventArgs e)
        {
            if (id.Text == "" || dataId <= 0)
                MessageBox.Show("Поле # должно быть целым числом > 0", "Неверно заполненные данные");

            else
            {
                bool found = false;
                for (int i = 0; i < table.Count; i++)
                {
                    Entry en = table[i];
                    if (en.No == dataId)
                    {
                        found = true;
                        en.species = (dataSpec != "")? dataSpec : en.species;
                        en.name = (dataName != "")? dataName: en.name;
                        en.age = (dataAge > 0)? dataAge : en.age;
                        en.owner = (dataOw != "")? dataOw : en.owner;
                        table[i] = en;
                        newjson = JsonSerializer.Serialize(table);
                        File.WriteAllText(path, newjson);
                        break;
                    }
                }
                if (!found) MessageBox.Show("Данные с номером " + dataId + " не найдены", "Данные не найдены");
            }
        }


        private void id_TextChanged(object sender, EventArgs e)
        {
            int.TryParse(id.Text, out dataId);
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
