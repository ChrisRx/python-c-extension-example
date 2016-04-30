# -*- coding: utf-8 -*-

import os
import sys
import re
from setuptools import setup, Extension, find_packages

def get_version():
    version_regex = re.compile(r'^__version__\s*=\s*[\'"]([^\'"]*)[\'"]', re.MULTILINE)

    with open('example/__init__.py', 'r') as f:
        return version_regex.search(f.read()).group(1)

def compile_ext():
    include_dirs = [os.path.join(os.getcwd(), "src")]
    libraries = []
    library_dirs = []
    extra_compile_args = ['-Wfatal-errors']
    linker_flags = ['-shared', '-Wl,--export-dynamic']

    sources = [
        "src/exampleobject.c",
        "src/module.c",
    ]

    depends = [
        "src/compat.h",
        "src/exampleobject.h",
    ]

    macros = []
    return Extension(
        "_modulename",
        language="c",
        extra_compile_args=extra_compile_args,
        library_dirs=library_dirs,
        libraries=libraries,
        include_dirs=include_dirs,
        define_macros=macros,
        sources=sources,
        depends=depends
    )

if __name__ == '__main__':
    setup(
        name="example",
        version=get_version(),
        packages=find_packages(exclude=['tests*']),
        scripts=[],
        ext_modules=[compile_ext()],
        entry_points={
            'console_scripts': [
                'examplecli = example.__main__:main'
            ]
        },
        zip_safe=False,
        package_dir={'example': 'example'},
        install_requires=[
        ],
        extras_require={
        },
        tests_require=[
        ],
        classifiers=[
            'Development Status :: 5 - Production/Stable',
            'Programming Language :: C',
            'Programming Language :: C++',
            'Programming Language :: Python',
            'Programming Language :: Python :: 2',
            'Programming Language :: Python :: 2.7',
            'Programming Language :: Python :: 3',
            'Programming Language :: Python :: 3.1',
            'Programming Language :: Python :: 3.2',
            'Programming Language :: Python :: 3.3',
            'Programming Language :: Python :: 3.4',
            'Programming Language :: Python :: 3.5',
            'Environment :: Console',
            'Intended Audience :: Developers',
            'Intended Audience :: System Administrators',
            'Intended Audience :: End Users/Desktop',
            'License :: OSI Approved :: Apache Software License',
            'Operating System :: POSIX :: Linux',
            'Topic :: Database',
            'Topic :: Software Development',
            'Topic :: Utilities'
        ]
    )
