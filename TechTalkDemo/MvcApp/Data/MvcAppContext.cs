using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using MvcApp.Models;

public class MvcAppContext : DbContext
{
    public MvcAppContext(DbContextOptions<MvcAppContext> options)
        : base(options)
    {
    }

    public DbSet<MvcApp.Models.User> User { get; set; } = default!;
}
