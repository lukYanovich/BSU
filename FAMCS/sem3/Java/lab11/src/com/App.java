package com;


import com.company.Account;
import com.additionalDialog.*;
import com.comparators.*;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.List;


public class App extends JFrame {
    private JPanel panelMain;

    private JButton file;
    private JButton sort;
    private JButton search;
    private JButton remove;

    private JRadioButton RadioButton1;
    private JRadioButton RadioButton2;
    private JRadioButton RadioButton3;
    private JRadioButton RadioButton4;

    private JTextArea text;
    private JLabel label;
    private JTextField textField1;

    private File usedFile = null;
    private List<Account> list = new ArrayList<>();

    private enum indexType {
        NUMBER_OF_HOUSE,
        NUMBER_OF_FLAT,
        FIO,
        DATE
    }

    private indexType statusOfSort = indexType.NUMBER_OF_HOUSE;
    private String index;


    private void textUpdate(List<Account> arr) {
        if (arr.isEmpty()) {
            JOptionPane.showMessageDialog(null,
                    "программа не работает на пустом файле");
        } else {
            StringBuilder s = new StringBuilder();
            for (Account i : arr)
                s.append(i);
            text.setText(s.toString());
        }
    }


    private void checkRadioButtons() {
        if (RadioButton1.isSelected())
            statusOfSort = indexType.NUMBER_OF_HOUSE;
        else if (RadioButton2.isSelected())
            statusOfSort = indexType.NUMBER_OF_FLAT;
        else if (RadioButton3.isSelected())
            statusOfSort = indexType.FIO;
        else if (RadioButton4.isSelected())
            statusOfSort = indexType.DATE;
    }


    private void writeInFile() {
        if (usedFile == null)
            return;
        usedFile.delete();
        try (RandomAccessFile raf = new RandomAccessFile(usedFile, "rw")) {
            for (Account i : list)
                Account.writeObject(raf, i);
        } catch (FileNotFoundException e) {
            JOptionPane.showMessageDialog(null, "файл не найден");
            e.printStackTrace();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "не смогли открыть файл для записи");
            e.printStackTrace();
        }
    }


    public App() {
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                writeInFile();
                super.windowClosing(e);
            }
        });

        file.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                writeInFile();

                JFileChooser fileopen = new JFileChooser();
                fileopen.setCurrentDirectory(new File("C:\\Projects\\FAMCS\\sem3\\Java\\lab11\\src\\com\\resources"));
                int ret = fileopen.showDialog(null, "Открыть файл");
                if (ret == JFileChooser.APPROVE_OPTION) {
                    usedFile = fileopen.getSelectedFile();
                }

                List<Account> arr = new ArrayList<>();
                try (RandomAccessFile raf = new RandomAccessFile(usedFile, "rw")) {
                    long pos = raf.getFilePointer();
                    while (pos < raf.length()) {
                        arr.add((Account) Account.readObject(raf, pos));
                        pos = raf.getFilePointer();
                    }
                    list = arr;
                } catch (FileNotFoundException e1) {
                    JOptionPane.showMessageDialog(null, "файл не найден");
                    e1.printStackTrace();
                    return;
                } catch (IOException e1) {
                    JOptionPane.showMessageDialog(null, "файл не открыт");
                    e1.printStackTrace();
                    return;
                } catch (ClassNotFoundException e1) {
                    JOptionPane.showMessageDialog(null, "ошибка с классом");
                    e1.printStackTrace();
                    return;
                }
                textUpdate(list);
            }
        });

        sort.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                SortDialog d = new SortDialog();
                d.setSize(new Dimension(250, 250));
                d.setVisible(true);

                checkRadioButtons();
                if (d.getStatus() == 1) {
                    switch (statusOfSort) {
                        case NUMBER_OF_HOUSE:
                            list.sort(new CompareByNumberOfHouseInc());
                            break;
                        case NUMBER_OF_FLAT:
                            list.sort(new CompareByNumberOfHouseInc());
                            break;
                        case FIO:
                            list.sort(new ComparebyFioInc());
                            break;
                        case DATE:
                            list.sort(new CompareByDateInc());
                            break;
                    }
                } else if (d.getStatus() == 2) {
                    switch (statusOfSort) {
                        case NUMBER_OF_HOUSE:
                            list.sort(new CompareByNumberOfHouseDec());
                            break;
                        case NUMBER_OF_FLAT:
                            list.sort(new CompareByNumberOfHouseDec());
                            break;
                        case FIO:
                            list.sort(new ComparebyFioDec());
                            break;
                        case DATE:
                            list.sort(new CompareByDateDec());
                            break;
                    }
                }
                textUpdate(list);
            }
        });

        search.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                SearchDialog d = new SearchDialog();
                d.setSize(new Dimension(250, 250));
                d.setVisible(true);

                if (textField1.getText().isEmpty()) {
                    JOptionPane.showMessageDialog(null, "введите ключ");
                    return;
                }
                checkRadioButtons();
                index = textField1.getText();
                List<Account> arr = new ArrayList<>();
                try {
                    switch (statusOfSort) {
                        case NUMBER_OF_HOUSE: {
                            Integer ind = Integer.parseInt(index);
                            switch (d.getStatus()) {
                                case 1: {
                                    for (Account i : list)
                                        if (i.getNumberOfHouse().compareTo(ind) == 0)
                                            arr.add(i);
                                    break;
                                }
                                case 2: {
                                    for (Account i : list)
                                        if (i.getNumberOfHouse().compareTo(ind) >= 0)
                                            arr.add(i);
                                    break;
                                }
                                case 3: {
                                    for (Account i : list)
                                        if (i.getNumberOfHouse().compareTo(ind) <= 0)
                                            arr.add(i);
                                    break;
                                }
                            }
                            break;
                        }
                        case NUMBER_OF_FLAT: {
                            Integer ind = Integer.parseInt(index);
                            switch (d.getStatus()) {
                                case 1: {
                                    for (Account i : list)
                                        if (i.getNumberOfFlat().compareTo(ind) == 0)
                                            arr.add(i);
                                    break;
                                }
                                case 2: {
                                    for (Account i : list)
                                        if (i.getNumberOfFlat().compareTo(ind) >= 0)
                                            arr.add(i);
                                    break;
                                }
                                case 3: {
                                    for (Account i : list)
                                        if (i.getNumberOfFlat().compareTo(ind) <= 0)
                                            arr.add(i);
                                    break;
                                }
                            }
                            break;
                        }
                        case FIO: {
                            switch (d.getStatus()) {
                                case 1: {
                                    for (Account i : list)
                                        if (i.getFio().compareTo(index) == 0)
                                            arr.add(i);
                                    break;
                                }
                                case 2: {
                                    for (Account i : list)
                                        if (i.getFio().compareTo(index) >= 0)
                                            arr.add(i);
                                    break;
                                }
                                case 3: {
                                    for (Account i : list)
                                        if (i.getFio().compareTo(index) <= 0)
                                            arr.add(i);
                                    break;
                                }
                            }
                            break;
                        }
                        case DATE: {
                            String[] s = textField1.getText().split("\\.");
                            Date ind = (new GregorianCalendar(Integer.parseInt(s[2]),
                                    Integer.parseInt(s[1]) + 1,
                                    Integer.parseInt(s[0]))).getTime();
                            switch (d.getStatus()) {
                                case 1: {
                                    for (Account i : list)
                                        if (i.getDateOfPayment().compareTo(ind) == 0)
                                            arr.add(i);
                                    break;
                                }
                                case 2: {
                                    for (Account i : list)
                                        if (i.getDateOfPayment().compareTo(ind) >= 0)
                                            arr.add(i);
                                    break;
                                }
                                case 3: {
                                    for (Account i : list)
                                        if (i.getDateOfPayment().compareTo(ind) <= 0)
                                            arr.add(i);
                                    break;
                                }
                            }
                            break;
                        }
                    }
                } catch (Throwable ex) {
                    JOptionPane.showMessageDialog(null, "несовпадение типов");
                    ex.printStackTrace();
                    return;
                }
                if (list.isEmpty())
                    JOptionPane.showMessageDialog(null, "файл пуст, совпадений не найдено");
                else if (arr.isEmpty())
                    JOptionPane.showMessageDialog(null, "совпадений не найдено");
                else
                    textUpdate(arr);
            }
        });

        remove.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (textField1.getText().isEmpty()) {
                    JOptionPane.showMessageDialog(null, "введите ключ");
                    return;
                }
                checkRadioButtons();
                index = textField1.getText();
                try {
                    switch (statusOfSort) {
                        case NUMBER_OF_HOUSE: {
                            Integer ind = Integer.parseInt(index);
                            for (int i = 0; i < list.size(); i++)
                                if (ind.compareTo(list.get(i).getNumberOfHouse()) == 0)
                                    list.remove(list.get(i));
                            break;
                        }
                        case NUMBER_OF_FLAT: {
                            Integer ind = Integer.parseInt(index);
                            for (int i = 0; i < list.size(); i++)
                                if (ind.compareTo(list.get(i).getNumberOfFlat()) == 0)
                                    list.remove(list.get(i));
                            break;
                        }
                        case FIO: {
                            for (int i = 0; i < list.size(); i++)
                                if (index.compareTo(list.get(i).getFio()) == 0)
                                    list.remove(list.get(i));
                            break;
                        }
                        case DATE: {
                            String[] s = textField1.getText().split("\\.");
                            Date ind = (new GregorianCalendar(Integer.parseInt(s[2]),
                                    Integer.parseInt(s[1]) + 1,
                                    Integer.parseInt(s[0]))).getTime();
                            for (int i = 0; i < list.size(); i++)
                                if (ind.compareTo(list.get(i).getDateOfPayment()) == 0)
                                    list.remove(list.get(i));
                            break;
                        }
                    }
                } catch (Throwable ex) {
                    JOptionPane.showMessageDialog(null, "несоответствие типов");
                    ex.printStackTrace();
                    return;
                }
                textUpdate(list);
            }
        });
    }


    public static void main(String[] args) {
        JFrame frame = new JFrame("GUI к заданию 8");
        frame.setContentPane(new App().panelMain);
        frame.pack();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setSize(new Dimension(700, 600));
    }
}
