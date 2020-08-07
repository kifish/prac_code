import topojson # install from https://github.com/sgillies
import json
import numpy as np

# https://plot.ly/~empet/14397/plotly-plot-of-a-map-from-data-available/#/
# 有问题
with open("china-provinces.json") as json_file:
    jdata = json_file.read()
    topoJSON = json.loads(jdata)


print(topoJSON.keys())
print(topoJSON['objects'].keys())
# dict_keys(['CHN_adm1'])

topo_features = topoJSON['objects']['geometries']
scale = topoJSON['transform']['scale']
translation = topoJSON['transform']['translate']

geoJSON=dict(type= 'FeatureCollection',
             features = [])

for k, tfeature in enumerate(topo_features):
    geo_feature = dict(id=k, type= "Feature")
    geo_feature['properties'] = tfeature['properties']
    geo_feature['geometry'] = topojson.geometry(tfeature, topoJSON['arcs'], scale, translation)
    geoJSON['features'].append(geo_feature)

print(geoJSON.keys())
print(len(geoJSON['features']))
# geoJSON['features'][0].keys()
# geoJSON['features'][0]['geometry'].keys()

pts = []  # list of points defining boundaries of polygons
for feature in geoJSON['features']:
    if feature['geometry']['type'] == 'Polygon':
        pts.extend(feature['geometry']['coordinates'][0])
        pts.append([None, None])  # mark the end of a polygon

    elif feature['geometry']['type'] == 'MultiPolygon':
        for polyg in feature['geometry']['coordinates']:
            pts.extend(polyg[0])
            pts.append([None, None])  # end of polygon
    else:
        raise ValueError("geometry type irrelevant for map")

