package pageObjects.com.flysas;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

public class PanelFlight {
    private WebDriver driver;

    private boolean two_way;
    private boolean date_return_is_clicked;
    private boolean date_from_is_clicked;
    private String city_to_path;
    private String city_from_path;
    private String date_return_path;
    private String date_from_path;
    private String button_search_path;

    public PanelFlight(WebDriver driver) {
        this.driver = driver;
        this.two_way = true;
        this.date_return_is_clicked = false;
        this.date_from_is_clicked = false;
        this.city_from_path="//*[@id=\"origin\"]";
        this.city_to_path = "//*[@id=\"destination\"]";
        this.date_return_path = "//*[@id=\"Inbound\"]";
        this.date_from_path="//*[@id=\"Outbound\"]";
        this.button_search_path="//*[@id=\"search-button\"]";
    }

    public void enableOneTrip() {
        if (this.two_way) {
            this.two_way = false;
            this.date_return_is_clicked=false;
            String path = "//*[@id=\"OW\"]";
            driver.findElement(By.xpath(path)).click();
        }
    }

    public void enableTwoWay(){
        if (!this.two_way){
            this.two_way=true;
            String path="//*[@id=\"RT\"]";
            driver.findElement(By.xpath(path)).click();
        }
    }

    public void set_city_to(String city) {
        WebElement city_to = driver.findElement(By.xpath(this.city_to_path));
        city_to.sendKeys(city);
    }

    public void set_city_from(String city){
        WebElement city_to = driver.findElement(By.xpath(this.city_from_path));
        city_to.sendKeys(city);
    }

    public void select_date_return(int tab, int tr, int td) {
        if (!this.date_return_is_clicked) {
            this.date_return_is_clicked = true;
            WebElement date_to_list = driver.findElement(By.xpath(this.date_return_path));
            date_to_list.click();
        }
        select_date(tab, td, tr);
    }

    public void select_date_from(int tab, int tr, int td) {
        if (!this.date_from_is_clicked) {
            this.date_from_is_clicked = true;
            WebElement date_from_list = driver.findElement(By.xpath(this.date_from_path));
            date_from_list.click();
        }
        select_date(tab, td, tr);
    }

    public String get_date_from() {
        WebElement date_from = driver.findElement(By.xpath(this.date_from_path));
        return date_from.getAttribute("value");
    }

    public void click_button_search() {
        WebElement button_search = driver.findElement(By.xpath(this.button_search_path));
        button_search.click();
    }

    //-----------------------------------------------------------------------------------------------------------------
    private void select_date(int tab, int tr, int td) {
        String date_path = "//*[@id=\"tab-1\"]/div/div["+tab+"]/table/tbody/tr[" + tr + "]/td[" + td + "]";
        WebElement date = driver.findElement(By.xpath(date_path));
        date.click();
    }
}
