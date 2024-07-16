package com.example.demo1;

import javafx.beans.property.SimpleStringProperty;

public class DetailedAnimal extends Animal{

    protected final SimpleStringProperty population;
     protected final SimpleStringProperty weight;

     protected DetailedAnimal(String m_animal, String m_species, String m_description, String m_population, String m_weight) {
         super(m_animal, m_species, m_description);
         this.population = new SimpleStringProperty(m_population);
         this.weight = new SimpleStringProperty(m_weight);
     }

    public String getPopulation() {
        return population.get();
    }

    public void setPopulation(String m_population) {
        weight.set(m_population);
    }

    public String getWeight() {
         return weight.get();
     }

     public void setWeight(String m_weight) {
         weight.set(m_weight);
     }
 }