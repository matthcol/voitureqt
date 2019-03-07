#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <QDebug>

#include "voiture.h"
#include <exception>
using namespace testing;

class TestOldVoitureRouler: public Test {
protected:
    int kmStart;
    int jaugeStart;
    Voiture oldCar;

    void SetUp() override {
        kmStart = 160000;
        jaugeStart = 1500;
        oldCar.setKilometrage(kmStart);
        oldCar.setJaugeCarburant(jaugeStart);
        oldCar.setModele("Ford Mustang 1967"); // just for fun
    }

    void TearDown() override {
        qDebug() << "Do some cleaning";
    }
};

TEST_F(TestOldVoitureRouler, OK)
{
    // given
    int distance = 100;
    // when
    oldCar.rouler(distance);
    // then
    EXPECT_EQ(oldCar.kilometrage(), kmStart + distance) << "Kilometrage incorrect";
    EXPECT_EQ(oldCar.jaugeCarburant(), jaugeStart - distance * 10)
            << "Jauge Carburant incorrecte";
}

TEST_F(TestOldVoitureRouler, NoGaz) {
    // given
    int distance = 200;
    // when/then
    EXPECT_THROW(oldCar.rouler(distance), std::invalid_argument);
    EXPECT_THAT(oldCar.kilometrage(), Eq(kmStart));
    EXPECT_THAT(oldCar.jaugeCarburant(), Eq(jaugeStart));
}

class TestVoitureRecenteRouler: public TestWithParam<int> {
};

TEST_P(TestVoitureRecenteRouler, Range)
{
    int kmStart = GetParam();
    int jaugeStart = 500;
    Voiture voiture("Ferrari F40", kmStart, jaugeStart);
    int distance = 100;
    // when
    voiture.rouler(distance);
    EXPECT_THAT(voiture.kilometrage(), Eq(kmStart + distance))
            << "Kilometrage incorrect";
    EXPECT_THAT(voiture.jaugeCarburant(), Eq(jaugeStart - distance * 5))
            << "Jauge Carburant incorrecte";
}

INSTANTIATE_TEST_SUITE_P(GroupVoitureRecente,TestVoitureRecenteRouler,
          Values(0, 10000, 149999)
       );


