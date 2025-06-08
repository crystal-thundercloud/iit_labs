<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <html>
            <head>
                <style>
                    .critters {
                        background-color: lightgreen;
                    }
                    .birds {
                        background-color: skyblue;
                    }
                    table {
                        background-color: moccasin;
                        padding: 10px;
                        border-spacing: 1 0;
                    }
                    table th {
                        background-color: pink;
                        font-size: 20px;
                    }
                    table td, table th {
                        padding: 10px;
                        text-align: center;
                        max-width: 333px;
                    }
                </style>
            </head>
            <body>
                <center>

                    <h2>
                        <xsl:value-of select="fauna/heading/@title" />
                    </h2>
                    <p>
                        <xsl:value-of select="fauna/heading" />
                    </p>
                    <table>
                        <tr>
                            <th>Вид</th>
                            <th>Питание</th>
                            <th>Отношение к игроку</th>
                            <th>Количество в биоме</th>
                            <th>Описание</th>
                        </tr>
                        <xsl:for-each select="fauna/animals/critter">
                            <tr class='critters'>
                                <td>
                                    <xsl:value-of select="name" />
                                </td>
                                <td>
                                    <xsl:value-of select="diet" />
                                </td>
                                <td>
                                    <xsl:value-of select="attitude" />
                                </td>
                                <td>
                                    <xsl:value-of select="number" />
                                </td>
                                <td>
                                    <xsl:value-of select="decription" />
                                </td>
                            </tr>
                        </xsl:for-each>
                        <xsl:for-each select="fauna/birds/critter">
                            <tr class='birds'>
                                <td>
                                    <xsl:value-of select="name" />
                                </td>
                                <td>
                                    <xsl:value-of select="diet" />
                                </td>
                                <td>
                                    <xsl:value-of select="attitude" />
                                </td>
                                <td>
                                    <xsl:value-of select="number" />
                                </td>
                                <td>
                                    <xsl:value-of select="decription" />
                                </td>
                            </tr>
                        </xsl:for-each>
                    </table>
                </center>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>