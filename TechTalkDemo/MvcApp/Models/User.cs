using System.ComponentModel.DataAnnotations;

namespace MvcApp.Models
{
    public class User
    {
        public int Id { get; set; }
        public string? Name { get; set; }

        [DataType(DataType.Date)]
        public DateTime Birthday { get; set; }
        public char Gender { get; set; }
        public int Age { get; set; }
    }
}