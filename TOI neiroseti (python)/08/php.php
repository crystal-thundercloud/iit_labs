<?php
$xml = new DOMDocument;
$xsl = new DOMDocument;

$xml->load('xml.xml');
$xsl->load('xsl.xsl');

$XSLTPprocessor = new XSLTProcessor;
$XSLTPprocessor->importStyleSheet($xsl);

echo $XSLTPprocessor->transformToXML($xml);
