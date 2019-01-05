package com.company.others;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;


@XmlRootElement
@XmlAccessorType(XmlAccessType.NONE)
public class Comand {

    @XmlElement(required = true)
    private String comand;


    public Comand(){}


    public Comand(String str) {
        this.comand = str;
    }
}
