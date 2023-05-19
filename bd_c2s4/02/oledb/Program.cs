using System.Data.OleDb;

namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            OleDbConnection oledb = new OleDbConnection();
            oledb.ConnectionString = @"Provider=SQLOLEDB; Data Source=ASNO; Initial Catalog=ShemarevaAM; User Id=ASNO\cdctt; Password=root; Integrated Security=SSPI;";
            
            OleDbCommand com = new OleDbCommand(); //Provider=sqloledb;Data Source=myServerAddress;Initial Catalog=myDataBase;User Id=myUsername;Password=myPassword;
            com.Connection = oledb;
            com.CommandText = "SELECT * FROM fruitz";
            
            OleDbDataReader reader;
            oledb.Open();
            reader = com.ExecuteReader();
            
            while (reader.Read()) {
                Console.WriteLine(reader.GetValue(0) + " " + reader.GetValue(1) + reader.GetValue(2));
            }
            
            oledb.Close();
        }
    }
}