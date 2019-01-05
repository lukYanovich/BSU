package pageObjects.com.flysas;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import pageObjects.Shell;

public class ChoiceLocation extends Shell {
    public ChoiceLocation(WebDriver driver) {
        super(driver);
    }

    public void close_choice_page() {
        String path = "//*[@id=\"ms-close\"]";
        WebElement cross = findElem(path);
        cross.click();
    }

    public void select_german_language() {
        String path = "//*[@id=\"market_DE\"]/a";
        WebElement temp = findElem(path);
        temp.click();
        path = "//*[@id=\"submit-market\"]";
        temp = findElem(path);
        temp.click();
    }
}
