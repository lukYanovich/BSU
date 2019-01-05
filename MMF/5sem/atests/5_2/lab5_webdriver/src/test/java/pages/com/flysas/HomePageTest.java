package pages.com.flysas;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import pageObjects.com.flysas.ChoiceLocation;
import pageObjects.com.flysas.PanelFlight;
import shell.ShellTests;

public class HomePageTest extends ShellTests {
    private ChoiceLocation choiceLocation;
    private PanelFlight panelFlight;

    @Before
    public void init() {
        driver.get("https://www.flysas.com");
        choiceLocation = new ChoiceLocation(driver);
        panelFlight = new PanelFlight(driver);
    }

    @Test
    public void Test1() {
        choiceLocation.close_choice_page();
        panelFlight.enableOneTrip();
        panelFlight.set_city_to("AMS");
        panelFlight.select_date_from(2, 2, 5);
        panelFlight.click_button_search();

        String second_page = "https://www.flysas.com/en/book/flights?search=OW_EWR-AMS-20190129_a1c0i0y0&view=upsell&bookingFlow=revenue";
        Assert.assertEquals(driver.getCurrentUrl(), second_page);
    }

    @Test
    public void Test2() {
        choiceLocation.close_choice_page();
        panelFlight.set_city_to("LAX");
        panelFlight.select_date_from(2, 5, 2);
        panelFlight.select_date_return(2, 3, 2);

        String date_expected = "Wed, 09 jan";
        String date_real = panelFlight.get_date_from();
        Assert.assertEquals(date_expected, date_real);
    }
}
