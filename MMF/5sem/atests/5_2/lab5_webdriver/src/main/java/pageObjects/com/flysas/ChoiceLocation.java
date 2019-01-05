package pageObjects.com.flysas;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class ChoiceLocation {
    private WebDriver driver;

    public ChoiceLocation(WebDriver driver) {
        this.driver = driver;
    }

    public void close_choice_page() {
        String path = "//*[@id=\"ms-close\"]";
        WebElement cross = driver.findElement(By.xpath(path));
        cross.click();
    }
}
