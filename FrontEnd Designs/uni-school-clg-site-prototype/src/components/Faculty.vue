<template>
  <section id="faculty" class="py-16">
    <div class="container mx-auto px-4">
      <h2 class="text-3xl font-bold mb-6 text-center underline">Our Faculty</h2>
      <div class="grid grid-cols-1 md:grid-cols-3 gap-6">
        <div v-for="(teacher, index) in teacher" class="p-6 rounded-md shadow-md text-center">
            <img :src="teacher.photo" alt="Faculty Photo" class="w-24 h-24 mx-auto mb-4 rounded-full object-cover"></img>
            <h3>{{ teacher.name }}</h3>
            <p>{{ teacher.title }}</p>
            <p>{{ teacher.bio }}</p>
        </div>
      </div>
    </div>
  </section>
</template>

<script setup>
// Use an array for faculty data; integrate backend for real profiles later
import {ref} from 'vue';

const teacher = ref([
{name: 'Dr.Emily Lee', photo: 'https://via.placholder.com/150', title: 'Lecturer in Arts', bio: 'Award-winning designer with a focus on digital design.'},
{name: 'Dr.Jane Smith', photo: 'https://via.placholder.com/150', title: 'Professor of Computer Science', bio: 'Expert in AI and Machine Learning with EXP of 15+ years.'},
{name: 'Dr.John Doe', photo: 'https://via.placholder.com/150', title: 'Head of Business Department', bio: 'Specializes in Management and has authored many books.'},
])
</script>
