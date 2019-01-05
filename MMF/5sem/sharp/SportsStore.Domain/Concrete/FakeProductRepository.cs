using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SportsStore.Domain.Abstract;
using SportsStore.Domain.Entities;

namespace SportsStore.Domain.Concrete
{
    public class FakeProductRepository : IProductRepository
    {
        private IList<Product> products = new List<Product>()
        {
            new Product(){ProductID = 1, Name = "Product 1v", Description = "Description product 1", Category = "Category A", Price = 12},
            new Product(){ProductID = 2, Name = "Product 2", Description = "Description product 2", Category = "Category A", Price = 132},
            new Product(){ProductID = 3, Name = "Product 3", Description = "Description product 3", Category = "Category A", Price = 312},
            new Product(){ProductID = 4, Name = "Product 4", Description = "Description product 4", Category = "Category A", Price = 128},
            new Product(){ProductID = 5, Name = "Product 5", Description = "Description product 5", Category = "Category A", Price = 112},
            new Product(){ProductID = 6, Name = "Product 6", Description = "Description product 6", Category = "Category B", Price = 62},
            new Product(){ProductID = 7, Name = "Product 7", Description = "Description product 7", Category = "Category B", Price = 64},
            new Product(){ProductID = 8, Name = "Product 8", Description = "Description product 8", Category = "Category B", Price = 45},
            new Product(){ProductID = 9, Name = "Product 9", Description = "Description product 9", Category = "Category B", Price = 90},
            new Product(){ProductID = 10, Name = "Product 10", Description = "Description product 10", Category = "Category C", Price = 32}
        };

        public IQueryable<Product> Products
        {
            get { return products.AsQueryable(); }
        }

        public void SaveProduct(Product product)
        {
            throw new NotImplementedException();
        }

        public Product DeleteProduct(int productID)
        {
            throw new NotImplementedException();
        }
    }
}
