#include "Taxonomy.h"

#include <fstream>
#include <iostream>
#include <QDebug>

//Taxonomy Taxonomy::fromJsonFile()
//{
//    std::ifstream file("D:/Dropbox/Julian/Ontology/MTG/AIT_MTG.json");
//    json data = json::parse(file);
//
//    Taxonomy taxonomy;
//    traverseTaxonomy(taxonomy, data);
//
//    return taxonomy;
//}

void Taxonomy::print()
{
    qDebug() << "============================";
    qDebug() << "\tTaxonomy";
    qDebug() << "============================";
    qDebug() << "Title:" << title;
    qDebug() << "Description:" << description;

    qDebug() << "Author:" << author_name;
    qDebug() << "Collaborators:" << author_list;
    qDebug() << "Author Contact:" << author_contact;
    qDebug() << "ORCID:" << orcid;

    qDebug() << "Cell Annotation Schema Version:" << cellannotation_schema_version;
    qDebug() << "Cell Annotation Version:" << cellannotation_version;
    qDebug() << "Cell Annotation Timestamp:" << cellannotation_timestamp;
    qDebug() << "Cell Annotation URL:" << cellannotation_url;

    qDebug() << "List of annotations:";
    for (Annotation& annotation : annotations)
    {
        qDebug() << "Annotation:" << annotation.labelset << "|" << annotation.cell_label;
    }
}
