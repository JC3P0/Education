package com.example.demo1;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableColumn.CellEditEvent;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import java.io.IOException;

public class HelloApplication extends Application {

     private TableView<Animal> table = new TableView<Animal>();
     private TableView<DetailedAnimal> table2 = new TableView<DetailedAnimal>();

     private final ObservableList<DetailedAnimal> data2 =
             FXCollections.observableArrayList(
             new DetailedAnimal("Rhinoceros", "Javan", "Height: 4-6 Feet, Length: 10 feet", "60", "2-5k lb"),
             new DetailedAnimal("Phocoena sinus", "Phocoenidae", "Located off the gulf of California. Trophic level: Carnivorous", "NA","43 kg"),
             new DetailedAnimal("Gorilla", "Beringei", "Unlike the western gorilla, there are few eastern gorillas in zoos.", "3k","600 lb"),
             new DetailedAnimal("Tiger", "Bengal", "Ranks among the biggest wild cats alive today.", "3.5k","200 - 350 lb"));

    private final ObservableList<Animal> data =
            FXCollections.observableArrayList(
                    new Animal("Rhinoceros", "Javan", "Population of 60, Habitat: Tropical Forests"),
                    new Animal("Phocoena sinus", "Phocoenidae", "Length: 1 - 1.5m(Adult)"),
                    new Animal("Gorilla", "Beringei", "Increasingly endangered since the 1990s."),
                    new Animal("Tiger", "Bengal", "Length: 9-10 Feet, Height: 3-3.6 Feet"));

    final HBox hb = new HBox();
    final HBox hb2 = new HBox();

    @Override
    public void start(Stage stage) throws IOException {

        final Button nextButton = new Button("Next");
        final Button backButton = new Button("Back");
        final Button addButton = new Button("Add");
//        final Button add2Button = new Button("Add");

        Scene scene = new Scene(new Group());

        stage.setTitle("Data:");
        stage.setWidth(750);
        stage.setHeight(530);
        final Label label = new Label("Endangered Animals");
        label.setFont(new Font("Arial", 20));

        final Label label2= new Label("Extra Info");
        label2.setFont(new Font("Arial", 20));

        table.setEditable(true);

        TableColumn animalCol = new TableColumn("Animal");
        animalCol.setMinWidth(100);
        animalCol.setCellValueFactory(
                new PropertyValueFactory<Animal, String>("animal"));
        animalCol.setCellFactory(TextFieldTableCell.forTableColumn());
        animalCol.setOnEditCommit(
                new EventHandler<CellEditEvent<Animal, String>>() {
                    @Override
                    public void handle(CellEditEvent<Animal, String> t) {
                        ((Animal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setAnimal(t.getNewValue());
                    }
                }
        );

        TableColumn speciesCol = new TableColumn("Species");
        speciesCol.setMinWidth(100);
        speciesCol.setCellValueFactory(
                new PropertyValueFactory<Animal, String>("species"));
        speciesCol.setCellFactory(TextFieldTableCell.forTableColumn());
        speciesCol.setOnEditCommit(
                new EventHandler<CellEditEvent<Animal, String>>() {
                    @Override
                    public void handle(CellEditEvent<Animal, String> t) {
                        ((Animal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setSpecies(t.getNewValue());
                    }
                }
        );

        TableColumn desCol = new TableColumn("Description");
        desCol.setMinWidth(510);
        desCol.setCellValueFactory(
                new PropertyValueFactory<Animal, String>("description"));
        desCol.setCellFactory(TextFieldTableCell.forTableColumn());
        desCol.setOnEditCommit(
                new EventHandler<CellEditEvent<Animal, String>>() {
                    @Override
                    public void handle(CellEditEvent<Animal, String> t) {
                        ((Animal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setDescription(t.getNewValue());
                    }
                }
        );

        table.setItems(data);
        table.getColumns().addAll(animalCol, speciesCol, desCol);

        final TextField addAnimal = new TextField();
        addAnimal.setPromptText("Animal");
        addAnimal.setMaxWidth(animalCol.getPrefWidth());
        final TextField addSpecies = new TextField();
        addSpecies.setMaxWidth(speciesCol.getPrefWidth());
        addSpecies.setPromptText("Species");
        final TextField addDescription = new TextField();
        addDescription.setMaxWidth(desCol.getPrefWidth());
        addDescription.setPromptText("Description");

        addButton.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                data.add(new Animal(
                        addAnimal.getText(),
                        addSpecies.getText(),
                        addDescription.getText()));
                addAnimal.clear();
                addSpecies.clear();
                addDescription.clear();
            }
        });

        //table 2
        table2.setEditable(true);

        TableColumn animal2Col = new TableColumn("AnimalName");
        animal2Col.setMinWidth(100);
        animal2Col.setCellValueFactory(
                new PropertyValueFactory<DetailedAnimal, String>("animal"));
        animal2Col.setCellFactory(TextFieldTableCell.forTableColumn());
        animal2Col.setOnEditCommit(
                new EventHandler<CellEditEvent<DetailedAnimal, String>>() {
                    @Override
                    public void handle(CellEditEvent<DetailedAnimal, String> t) {
                        ((DetailedAnimal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setAnimal(t.getNewValue());
                    }
                }
        );

        TableColumn species2Col = new TableColumn("SpeciesName");
        species2Col.setMinWidth(100);
        species2Col.setCellValueFactory(
                new PropertyValueFactory<DetailedAnimal, String>("species"));
        species2Col.setCellFactory(TextFieldTableCell.forTableColumn());
        species2Col.setOnEditCommit(
                new EventHandler<CellEditEvent<DetailedAnimal, String>>() {
                    @Override
                    public void handle(CellEditEvent<DetailedAnimal, String> t) {
                        ((DetailedAnimal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setSpecies(t.getNewValue());
                    }
                }
        );

        TableColumn des2Col = new TableColumn("Description");
        des2Col.setMinWidth(390);
        des2Col.setCellValueFactory(
                new PropertyValueFactory<DetailedAnimal, String>("description"));
        des2Col.setCellFactory(TextFieldTableCell.forTableColumn());
        des2Col.setOnEditCommit(
                new EventHandler<CellEditEvent<DetailedAnimal, String>>() {
                    @Override
                    public void handle(CellEditEvent<DetailedAnimal, String> t) {
                        ((DetailedAnimal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setDescription(t.getNewValue());
                    }
                }
        );

        TableColumn populationCol = new TableColumn("Pop.");
        populationCol.setMinWidth(50);
        populationCol.setCellValueFactory(
                new PropertyValueFactory<DetailedAnimal, String>("population"));
        populationCol.setCellFactory(TextFieldTableCell.forTableColumn());
        populationCol.setOnEditCommit(
                new EventHandler<CellEditEvent<DetailedAnimal, String>>() {
                    @Override
                    public void handle(CellEditEvent<DetailedAnimal, String> t) {
                        ((DetailedAnimal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setPopulation(t.getNewValue());
                    }
                }
        );

        TableColumn weightCol = new TableColumn("Weight");
        weightCol.setMinWidth(75);
        weightCol.setCellValueFactory(
                new PropertyValueFactory<DetailedAnimal, String>("weight"));
        weightCol.setCellFactory(TextFieldTableCell.forTableColumn());
        weightCol.setOnEditCommit(
                new EventHandler<CellEditEvent<DetailedAnimal, String>>() {
                    @Override
                    public void handle(CellEditEvent<DetailedAnimal, String> t) {
                        ((DetailedAnimal) t.getTableView().getItems().get(
                                t.getTablePosition().getRow())
                        ).setWeight(t.getNewValue());
                    }
                }
        );

        table2.setItems(data2);
        table2.getColumns().addAll(animal2Col, species2Col, des2Col, populationCol, weightCol);

        final TextField addAnimal2 = new TextField();
        addAnimal2.setPromptText("Animal");
        addAnimal2.setMaxWidth(animal2Col.getPrefWidth());
        final TextField addSpecies2 = new TextField();
        addSpecies2.setMaxWidth(species2Col.getPrefWidth());
        addSpecies2.setPromptText("Species");
        final TextField addDes2 = new TextField();
        addDes2.setMaxWidth(des2Col.getPrefWidth());
        addDes2.setPromptText("Description");
        final TextField addPopulation = new TextField();
        addPopulation.setMaxWidth(populationCol.getPrefWidth());
        addPopulation.setPromptText("Population");
        final TextField addWeight = new TextField();
        addWeight.setMaxWidth(weightCol.getPrefWidth());
        addWeight.setPromptText("Weight");

        final Button add2Button = new Button("Add");
        add2Button.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                data2.add(new DetailedAnimal(
                        addAnimal2.getText(),
                        addSpecies2.getText(),
                        addDes2.getText(),
                        addPopulation.getText(),
                        addWeight.getText()));
                addAnimal2.clear();
                addSpecies2.clear();
                addDes2.clear();
                addPopulation.clear();
                addWeight.clear();
            }
        });

        hb.getChildren().addAll(addAnimal, addSpecies, addDescription, addButton, nextButton);
        hb.setSpacing(4);

        hb2.getChildren().addAll(addAnimal2, addSpecies2, addDes2, addPopulation, addWeight, add2Button, backButton);
        hb2.setSpacing(4);

        final VBox vbox = new VBox();
        vbox.setSpacing(5);
        vbox.setPadding(new Insets(10, 0, 0, 10));
        vbox.getChildren().addAll(label, table, hb);

        final VBox layout2= new VBox();
        layout2.setSpacing(5);
        layout2.setPadding(new Insets(10, 0, 0, 10));
        layout2.getChildren().addAll(label2, table2, hb2);

        ((Group) scene.getRoot()).getChildren().addAll(vbox);

        Scene scene2= new Scene(layout2,530,750);
        nextButton.setOnAction(e -> stage.setScene(scene2));
        backButton.setOnAction(e -> stage.setScene(scene));

        stage.setScene(scene);
        stage.show();

    }

    public static void main(String[] args) {

        launch();
    }
}