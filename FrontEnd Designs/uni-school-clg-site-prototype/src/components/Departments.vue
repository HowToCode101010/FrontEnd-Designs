<template>
  <section id="departments" class="py-16">
    <div class="container mx-auto px-4">
      <h2 class="text-3xl font-bold mb-6 text-center underline">Our Departments</h2>
      <div class="grid grid-cols-1 md:grid-cols-3 gap-6">
      <div v-for = "(dept, index) in departments" :key="index" class="p-6 rounded-md shadow-md">
        <h3 class="text-xl font-semibold mb-2 underline">{{ dept.name }}</h3>
        <p>{{ dept.description }}</p>
      </div>
        </div>
      </div>
  </section>
</template>

<script setup>
import { ref } from 'vue';

const departments = ref([
  { name: 'Computer Science', description: 'Focusing on technology, software development, and AI.' },
  { name: 'Business Administration', description: 'Training in management, finance, and entrepreneurship.' },
  { name: 'Arts and Design', description: 'Creative programs in graphic design and visual arts.' }
  // Add more here as needed
]);
</script>
