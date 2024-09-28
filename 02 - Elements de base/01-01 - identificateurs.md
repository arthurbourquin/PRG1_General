# Identificateurs (noms des variables) en c++

`james_bond_007`  | Oui |
`james_bond__007` | Oui | Plusieurs _ peuvent se suivre |
`sOs`             | Oui |
`SOS`             | Oui | Vu que C++ tient compte de la casse, 5) est un identificateur différent de 6) |
`_007`            | Oui | Un identificateur peut commencer par _ |
`__007`           | Oui |
`_007_`           | Oui |
`INT`             | Oui | Déconseillé toutefois ! |
`_`               | Oui | … mais pas des plus parlants (!) |

`7`               | Non | Un identificateur ne peut pas commencer par un chiffre |
`james bond`      | Non | Pas d'espace dans un identificateur |
`bond-007`        | Non | Le caractère '-' n'est pas autorisé |
`tom&jerry`       | Non | Le caractère '&' n'est pas autorisé |
`int`             | Non | Mot réservé |
`André`           | Non | Les lettres accentuées ne sont pas autorisées |
