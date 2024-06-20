import yaml

def get_version(path):
    with open(path, 'r') as file:
        data = yaml.safe_load(file)
    return data['version']

def increment_minor(version):
    major, minor, patch = map(int, version.split('.'))
    minor += 1
    new_version = f"{major}.{minor}.{patch}"
    return new_version

def update_version(path, version):
    with open(path, 'r') as file:
        data = yaml.safe_load(file)

    data['version'] = version

    with open(path, 'w') as file:
        yaml.dump(data, file, default_flow_style=False)

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python update_version.py <path_to_yml>")
        sys.exit(1)

    path_to_yml = sys.argv[1]
    current_version = get_version(path_to_yml)
    new_version = increment_minor(current_version)
    update_version(path_to_yml, new_version)
    print(new_version)
