package pageObjects;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;

import java.util.concurrent.TimeUnit;

public class Shell {
    protected WebDriver driver;

    public Shell(WebDriver driver) {
        this.driver = driver;
    }

    protected void sleep() {
        long timeout = 30;
        driver.manage().timeouts().setScriptTimeout(timeout, TimeUnit.SECONDS);
        driver.manage().timeouts().implicitlyWait(timeout, TimeUnit.SECONDS);
        driver.manage().timeouts().pageLoadTimeout(timeout, TimeUnit.SECONDS);
    }

    protected void sleep(double sec) {
        sleep();
        try {
            Thread.sleep((long) (1000 * sec));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    protected WebElement findElem(String path) {
        //return driver.findElement(By.xpath(path));
        return (new WebDriverWait(driver, 10)).until(ExpectedConditions.presenceOfElementLocated(By.xpath(path)));
    }
}
