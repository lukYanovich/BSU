package pages.aero.windrose;

import org.junit.Assert;
import org.junit.Test;
import org.openqa.selenium.By;
import shell.ShellTests;

public class HomePageTest extends ShellTests {
    @Test
    public void Test1() {
        driver.get("https://www.flysas.com");

        driver.findElement(By.xpath("//*[@id=\"ms-close\"]")).click();
        driver.findElement(By.xpath("//*[@id=\"OW\"]")).click();
        driver.findElement(By.xpath("//*[@id=\"destination\"]")).sendKeys("AMS");
        driver.findElement(By.xpath("//*[@id=\"Outbound\"]")).click();
        driver.findElement(By.xpath("//*[@id=\"tab-1\"]/div/div[2]/table/tbody/tr[2]/td[5]/span")).click();
        driver.findElement(By.xpath("//*[@id=\"search-button\"]")).click();

        String second_page = "https://www.flysas.com/en/book/flights?search=OW_EWR-AMS-20190111_a1c0i0y0&view=upsell&bookingFlow=revenue";
        Assert.assertEquals(driver.getCurrentUrl(), second_page);
    }
}
