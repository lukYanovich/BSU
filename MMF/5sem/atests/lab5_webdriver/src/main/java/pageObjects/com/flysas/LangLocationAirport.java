package pageObjects.com.flysas;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import pageObjects.Shell;

public class LangLocationAirport extends Shell {

    private String language_path;
    private String location_path;
    private String airport_path;
    private String save_change_button_path;

    public LangLocationAirport(WebDriver driver) {
        super(driver);

        this.language_path = "//*[@id=\"language\"]";
        this.location_path = "//*[@id=\"location\"]";
        this.airport_path = "//*[@id=\"airport\"]";
        this.save_change_button_path = "//*[@id=\"market-selectors\"]/div[4]/button";
    }

    public String get_language() {
        WebElement language = findElem(this.language_path);
        return language.getAttribute("value");
    }

    public void save_changes() {
        WebElement button_save = findElem(this.save_change_button_path);
        button_save.click();
    }
}
