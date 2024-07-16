package com.example.demo1;

import javafx.beans.property.SimpleStringProperty;
import java.lang.String;

public class Animal {
    protected final SimpleStringProperty animal;
    protected final SimpleStringProperty species;
    protected final SimpleStringProperty description;

    protected Animal(String m_animal, String m_species, String m_description) {
        this.animal = new SimpleStringProperty(m_animal);
        this.species = new SimpleStringProperty(m_species);
        this.description = new SimpleStringProperty(m_description);
    }

    public String getSpecies() {
        return species.get();
    }
    public void setSpecies(String m_species) {
        species.set(m_species);
    }

    public String getAnimal() {
        return animal.get();
    }
    public void setAnimal(String m_animal) {
        animal.set(m_animal);
    }

    public String getDescription() {
        return description.get();
    }
    public void setDescription(String m_description) {
        description.set(m_description);
    }

}