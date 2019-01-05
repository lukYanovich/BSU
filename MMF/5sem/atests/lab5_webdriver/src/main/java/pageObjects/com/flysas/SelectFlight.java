package pageObjects.com.flysas;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import pageObjects.Shell;

public class SelectFlight extends Shell {
    private String message_alert_path;

    public SelectFlight(WebDriver driver) {
        super(driver);
        this.message_alert_path = "//*[@id=\"lpc-error\"]/p";
    }

    public String get_message_alert() {
        //sleep(6.2);
        sleep();
        WebElement alert = findElem(this.message_alert_path);
        return alert.getText();
    }
}
