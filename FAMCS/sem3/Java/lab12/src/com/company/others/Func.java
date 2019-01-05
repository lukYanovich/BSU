package com.company.others;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;


public class Func {

    public static String readFromXML(ObjectInputStream ois) throws XMLStreamException {

        XMLStreamReader xmlr = XMLInputFactory.newInstance().createXMLStreamReader(ois);

        while (xmlr.hasNext()) {
            xmlr.next();
            if (xmlr.hasText() && xmlr.getText().trim().length() > 0)
                return xmlr.getText();
        }
        return null;
    }


    public static void writeToXML(ObjectOutputStream oos, String str) throws JAXBException {

        JAXBContext jaxbContext = JAXBContext.newInstance(Comand.class);
        Marshaller jaxbMarsaller = jaxbContext.createMarshaller();

        jaxbMarsaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);

        jaxbMarsaller.marshal(new Comand(str), oos);
    }
}
