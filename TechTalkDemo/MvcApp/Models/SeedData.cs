using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using System;
using System.Linq;

namespace MvcApp.Models
{
    public static class SeedData
    {
        public static void Initialize(IServiceProvider serviceProvider)
        {
            using (var context = new MvcAppContext(
                serviceProvider.GetRequiredService<
                    DbContextOptions<MvcAppContext>>()))
            {
                if (context.User.Any())
                    return;

                context.User.AddRange(
                    new User
                    {
                        Name = "Li Xiang",
                        Birthday = DateTime.Parse("1989-2-12"),
                        Gender = 'M',
                        Age = 15
                    },
                    new User
                    {
                        Name = "Lv Bu",
                        Birthday = DateTime.Parse("1999-3-17"),
                        Gender = 'M',
                        Age = 27
                    },
                    new User
                    {
                        Name = "Diao Chan",
                        Birthday = DateTime.Parse("2000-4-15"),
                        Gender = 'F',
                        Age = 20
                    },
                    new User
                    {
                        Name = "Li Kui",
                        Birthday = DateTime.Parse("1974-2-12"),
                        Gender = 'M',
                        Age = 40
                    }
                );
                context.SaveChanges();
            }
        }
    }
}