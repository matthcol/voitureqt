#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "voiture.h"
using namespace testing;

TEST(TestVoitureConstructor, Default)
{
    Voiture voiture;
    EXPECT_EQ(voiture.modele(), "");
    EXPECT_EQ(voiture.kilometrage(), 0);
    EXPECT_EQ(voiture.jaugeCarburant(), 0);
}

TEST(TestVoitureConstructor, Complet)
{
    QString modele = "Ferrari F40";
    int km = 20000;
    int jauge= 5000;
    Voiture voiture(modele, km, jauge);
    EXPECT_EQ(voiture.modele(), modele);  // basé sur ==
    EXPECT_EQ(voiture.kilometrage(), km);
    EXPECT_EQ(voiture.jaugeCarburant(), jauge);
    //ASSERT_THAT(0, Eq(0));
}
