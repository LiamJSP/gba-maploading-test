import json

def convert_tiled_to_gba(tiled_json_path, output_path):
    # Load the Tiled JSON
    with open(tiled_json_path, 'r') as f:
        data = json.load(f)
    
    # For the current given scenario, Tiled tile IDs start at 1 and grit's start at 0.
    # So, subtract 1 from each tile ID in the map data.
    for layer in data['layers']:
        if 'data' in layer:
            layer['data'] = [tile_id - 1 for tile_id in layer['data']]
    
    # Save the modified JSON
    with open(output_path, 'w') as f:
        json.dump(data, f, indent=4)

# Use the function
tiled_json_path = 'brintestmap.json'
output_path = 'converted_map.json'
convert_tiled_to_gba(tiled_json_path, output_path)

print(f"Converted Tiled JSON saved to {output_path}")

