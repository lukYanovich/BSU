package com.company.entity;

public class Group_Score {
    private Integer group;
    private Double score;

    public Group_Score(Integer group,Double score){
        this.group=group;
        this.score=score;
    }

    @Override
    public String toString() {
        return group +" " + score;
    }

    public Integer getGroup() {
        return group;
    }

    public void setGroup(Integer group) {
        this.group = group;
    }

    public Double getScore() {
        return score;
    }

    public void setScore(Double score) {
        this.score = score;
    }
}
