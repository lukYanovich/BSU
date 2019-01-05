package com.company;

import java.io.*;
import java.util.Date;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;
import java.util.zip.ZipOutputStream;


public class Account implements Serializable{
    private static final long serialVersionUID = 1L;

    private Integer numberOfHouse;
    private Integer numberOfFlat;
    private String address;
    private String fio;
    private Date dateOfPayment;
    private Integer amount;
    private Integer percent;
    private Integer arrears;

    public Account(int numberOfHouse, int numberOfFlat, String address, String fio,
                   Date dateOfPayment, int amount, int percent, int arrears) {
        this.numberOfHouse = numberOfHouse;
        this.numberOfFlat = numberOfFlat;
        this.address = address;
        this.fio = fio;
        this.dateOfPayment = dateOfPayment;
        this.amount = amount;
        this.percent = percent;
        this.arrears = arrears;
    }

    private Account() {}

    private static byte[] toByteArray( Serializable obj ) throws IOException {
        ByteArrayOutputStream bufOut = new ByteArrayOutputStream();
        try ( ZipOutputStream zos = new ZipOutputStream( bufOut )) {
            zos.putNextEntry(new ZipEntry("r"));
            try (ObjectOutputStream oos = new ObjectOutputStream(zos)) {
                oos.writeObject(obj);
                oos.flush();
                zos.closeEntry();
                zos.flush();
                return bufOut.toByteArray();
            }
        }
    }


    public static void writeObject( RandomAccessFile file,
                                    Serializable obj ) throws IOException {
        file.seek( file.length() );
        byte[] what = toByteArray( obj );
        file.writeInt( what.length );
        file.write( what );
        file.setLength( file.getFilePointer() );
    }


    static Object fromByteArray( byte[] arr ) throws IOException, ClassNotFoundException {
        ByteArrayInputStream bufIn = new ByteArrayInputStream( arr );
        try( ZipInputStream zis = new ZipInputStream( bufIn )) {
            zis.getNextEntry();
            try ( ObjectInputStream ois = new ObjectInputStream( zis )) {
                return ois.readObject();
            }
        }
    }


    public static Object readObject( RandomAccessFile file, long position )
                        throws IOException, ClassNotFoundException {
        file.seek( position );
        int length = file.readInt();
        byte[] what = new byte[length];
        file.read( what );
        return fromByteArray( what );
    }


    @Override
    public String toString() {
        return "номер дома = \"" + numberOfHouse + "\"" +
                "\nномер квартиры = \"" + numberOfFlat + "\"" +
                "\nадрес = \"" + address + "\"" +
                "\nФИО владельца = \"" + fio + "\"" +
                "\nдата платежа = \"" + dateOfPayment + "\"" +
                "\nсумма платежа = \"" + amount + "\"" +
                "\nпроцент пени = \"" + percent + "\"" +
                "\nна сколько дней просрочен платёж = \"" + arrears + "\"" +
                "\n\n";
    }

    public Integer getNumberOfHouse() {
        return numberOfHouse;
    }

    public Integer getNumberOfFlat() {
        return numberOfFlat;
    }

    public String getFio() {
        return fio;
    }

    public Date getDateOfPayment() {
        return dateOfPayment;
    }
}
