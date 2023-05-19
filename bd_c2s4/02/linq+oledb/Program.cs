using System.Data.OleDb;
using System.Data;

namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            OleDbConnection oledb = new OleDbConnection();
            oledb.ConnectionString = @"Provider=SQLOLEDB; Data Source=ASNO; Initial Catalog=ShemarevaAM; User Id=ASNO\cdctt; Password=root; Integrated Security=SSPI;";

            oledb.Open();

            OleDbDataAdapter adap = new OleDbDataAdapter("Select * FROM fruitz", oledb);
            
            DataSet ds = new DataSet();
            adap.Fill(ds);

            adap.Dispose(); // очистить адаптер от полученных данных

            DataTable fruits = ds.Tables[0];

            // linq это вот эта штука
            IEnumerable<DataRow> query =
                from fruit in fruits.AsEnumerable()
                where fruit.Field<int>("amount") > 10
                select fruit;

            foreach (DataRow row in query) {
                Console.WriteLine("#" + row.Field<int>("id") + " " + row.Field<string>("fruit") + row.Field<int>("amount"));
            }

            // другой вариант вывода
            // for (int i = 0; i <= ds.Tables[0].Rows.Count - 1; i++) {
            //     Console.WriteLine(ds.Tables[0].Rows[i].ItemArray[0] + " фып" + ds.Tables[0].Rows[i].ItemArray[1] + " " + ds.Tables[0].Rows[i].ItemArray[2]);
            // }

            oledb.Close();
        }
    }
}