def get_attribute_dictionary(row):
    dict_attrs = {}
    tokens = row.split(' ')
    for i in range(1, len(tokens), 3):
        dict_attrs[tokens[i]] = tokens[i + 2].replace('>', '')[1:-1]
    return dict_attrs


def is_start_tag(row):
    return not row[0:2] == '</'


def is_end_tag(row):
    return row[0:2] == '</'


def get_tag_name(row):
    if is_start_tag(row):
        return row.split(' ')[0][1:]
    else:
        return row.split(' ')[0][2:-1]


def get_full_map(rows):
    tree = {}
    list_active_tags = []
    for row in rows:
        tag_name = get_tag_name(row)
        if is_start_tag(row):
            dict_attr = get_attribute_dictionary(row)
            list_active_tags.append(tag_name)
            tree['.'.join(list_active_tags)] = dict_attr
        else:
            list_active_tags.pop()
    return tree


def process_queries(parsed_tree, queries):
    for query in queries:
        attribute = query.split('~')[1]
        tags_hierarchy = query.split('~')[0]
        if attribute not in parsed_tree[tags_hierarchy]:
            print('NotFound')
        else:
            print(parsed_tree[tags_hierarchy][attribute])


if __name__ == '__main__':
    result = get_attribute_dictionary('<tag1 name = "name1" name2 = "val2" name3 = "abcd">')
    print(result)
    data = ['<tag1 value = "HelloWorld">',
            '<tag2 name = "Name1">',
            '<tag3 attrib = "Value1">',
            '</tag3>',
            '</tag2>',
            '<tag4 attrib1 = "val1" attrib2 = "val2">',
            '</tag4>',
            '</tag1>']
    parsed_html = get_full_map(data)
    print(parsed_html)
    queries = [
        'tag1.tag2~name',
        'tag1~name',
        'tag1~value',
        'tag1.tag2.tag3~attrib',
        'tag1.tag4~attrib2',
        'tag1.tag4~attrib3'
    ]
    process_queries(parsed_tree=parsed_html, queries=queries)