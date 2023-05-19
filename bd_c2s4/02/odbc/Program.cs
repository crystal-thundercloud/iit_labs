using System.Data.Odbc;

namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            OdbcConnection odbc = new OdbcConnection();
            odbc.ConnectionString = @"Driver={ODBC Driver 17 for SQL Server}; Server=ASNO; Database=ShemarevaAM; Uid=ASNO\cdctt; Pwd=root; Trusted_Connection=Yes;";
            
            odbc.Open();

            OdbcCommand com = new OdbcCommand("SELECT * FROM fruitz", odbc); //Driver={SQL Server};Server=myServerAddress;Database=myDataBase;Uid=myUsername;Pwd=myPassword;Password=myPassword; Trusted_Connection=Yes;
            
            //com.ExecuteNonQuery(); // выполнить команду
            
            OdbcDataReader reader = com.ExecuteReader();
            
            while (reader.Read()) {
                Console.WriteLine(reader.GetValue(0) + " " + reader.GetValue(1)+ " " + reader.GetValue(2));
            }
            
            reader.Close();
            odbc.Close();
        }
    }
}